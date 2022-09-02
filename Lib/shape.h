#pragma once
#include <iostream>
#include <string>
#include <fstream>


namespace geometry
{
	using namespace std;

	//абстрактний клас
	class Shape
	{

	protected:
		string name = "no_name";
		int x{}, y{};
		string fileName = "shape.txt";

	public:
		Shape() { }
		~Shape() { }
		virtual void Show() = 0;
		virtual void Save() = 0;
		virtual void Load(int index) = 0;
		virtual double area() = 0;
		virtual double perimeter() = 0;


	};

	//Клас Квадрат
	class Square : public Shape
	{
	protected:
		//довжина сторони
		double a{};

	public:
		Square() {}
		Square(int x, int y, double a)
		{
			name = "Квадрат";
			this->x = x;
			this->y = y;
			this->a = a;
		}
		~Square() { }
		virtual void Show() override;
		virtual void Save() override;
		virtual void Load(int index) override;
		virtual double area() override { return a * a; }
		virtual double perimeter() override { return 4 * a; }
	};

	//Клас Прямокутник
	class Reactangle : public Shape
	{
	protected:
		//довжина сторони
		double a{};
		//ширина сторони
		double b{};

	public:
		Reactangle() {}
		Reactangle(int x, int y, double a, double b)
		{
			this->name = "Прямокутник";
			this->x = x;
			this->y = y;
			this->a = a;
			this->b = b;
		}
		~Reactangle() { }
		virtual void Show() override;
		virtual void Save() override;
		virtual void Load(int index) override;
		virtual double area() override { return a * b; }
		virtual double perimeter() override { return 2 * (a + b); }
	};

	//Клас Коло
	class Circle : public Shape
	{
	protected:
		//радіус
		double r{};

	public:
		Circle() {}
		Circle(int x, int y, double r)
		{
			name = "Коло";
			this->x = x;
			this->y = y;
			this->r = r;
		}
		~Circle() { }
		virtual void Show() override;
		virtual void Save() override;
		virtual void Load(int index) override;
		virtual double area() override { return (3.14 * 2 * r); }
		virtual double perimeter() override { return (3.14 * r * r); }
	};

	//клас Еліпс
	class Elipse : public Reactangle
	{

	public:
		Elipse() {}
		Elipse(int x, int y, double a, double b)
		{
			this->name = "Еліпс";
			this->x = x;
			this->y = y;
			this->a = a / 2;
			this->b = b / 2;
		}
		~Elipse() { }
		virtual void Show() override;
		virtual void Save() override;
		virtual void Load(int index) override;
		virtual double area() override { return a * b * 3.14; }
		virtual double perimeter() override { return ((3.14 * a * b) + (a * a + b * b + 2 * a * b) / a + b); }
	};

	//Методи класів
	void Square::Show()
	{
		if (name != "no_name")
		{
			cout << name << '\n';
			cout << "Координати верхнього лівого кута ";
			cout << "X = " << x << ' ';
			cout << "Y = " << y << '\n';
			cout << "Довжина сторони = " << a << '\n';
			cout << "Площа = " << area() << '\n';
			cout << "Периметр = " << perimeter() << '\n';
		}
	}

	void Square::Save()
	{
		std::ofstream fout;
		fout.open(fileName, ios::app);

		if (!fout)
		{
			std::cerr << "Помилка збереження файлу...\n";
			exit(1);
		}

		fout << name << ' ' << x << ' ' << y << ' ' << a << '\n';
		fout.close();
	}

	void Square::Load(int index)
	{
		string temp;
		int count = -1;


		ifstream fin;
		fin.open(fileName, ios::in);

		if (!fin)
		{
			std::cerr << "Помилка читання файлу...\n";
			exit(1);
		}

		if (fin.is_open())
		{
			do
			{
				count++;
				if (count == index) fin >> this->name >> this->x >> this->y >> this->a;
				getline(fin, temp);

			} while (count != index);
		}

		fin.close();
	}

	void Reactangle::Show()
	{
		if (name != "no_name")
		{
			cout << name << '\n';
			cout << "Координати верхнього лівого кута ";
			cout << "X = " << x << ' ';
			cout << "Y = " << y << '\n';
			cout << "Довжина сторони = " << a << '\n';
			cout << "Ширина сторони = " << b << '\n';
			cout << "Площа = " << area() << '\n';
			cout << "Периметр = " << perimeter() << '\n';
		}
	}

	void Reactangle::Save()
	{
		std::ofstream fout;
		fout.open(fileName, ios::app);

		if (!fout)
		{
			std::cerr << "Помилка збереження файлу...\n";
			exit(1);
		}

		fout << name << ' ' << x << ' ' << y << ' ' << a << ' ' << b << '\n';
		fout.close();
	}

	void Reactangle::Load(int index)
	{
		string temp;
		int count = -1;


		ifstream fin;
		fin.open(fileName, ios::in);

		if (!fin)
		{
			std::cerr << "Помилка читання файлу...\n";
			exit(1);
		}

		if (fin.is_open())
		{
			do
			{
				count++;
				if (count == index) fin >> this->name >> this->x >> this->y >> this->a >> this->b;
				getline(fin, temp);

			} while (count != index);
		}

		fin.close();
	}

	void Circle::Show()
	{
		if (name != "no_name")
		{
			cout << name << '\n';
			cout << "Координати центра ";
			cout << "X = " << x << ' ';
			cout << "Y = " << y << '\n';
			cout << "Радіус = " << r << '\n';
			cout << "Площа = " << area() << '\n';
			cout << "Периметр = " << perimeter() << '\n';
		}
	}

	void Circle::Save()
	{
		std::ofstream fout;
		fout.open(fileName, ios::app);

		if (!fout)
		{
			std::cerr << "Помилка збереження файлу...\n";
			exit(1);
		}

		fout << name << ' ' << x << ' ' << y << ' ' << r << '\n';
		fout.close();
	}

	void Circle::Load(int index)
	{
		string temp;
		int count = -1;


		ifstream fin;
		fin.open(fileName, ios::in);

		if (!fin)
		{
			std::cerr << "Помилка читання файлу...\n";
			exit(1);
		}

		if (fin.is_open())
		{
			do
			{

				count++;
				if (count == index) fin >> this->name >> this->x >> this->y >> this->r;
				getline(fin, temp);

			} while (count != index);
		}

		fin.close();
	}

	void Elipse::Show()
	{
		if (name != "no_name")
		{
			cout << name << '\n';
			cout << "Координати верхньої точки прямокутника у якому вписаний еліпс ";
			cout << "X = " << x << ' ';
			cout << "Y = " << y << '\n';
			cout << "Велика полувісь еліпса = " << a << '\n';
			cout << "Мала полувісь еліпса  = " << b << '\n';
			cout << "Площа = " << area() << '\n';
			cout << "Периметр = " << perimeter() << '\n';
		}
	}

	void Elipse::Save()
	{
		std::ofstream fout;
		fout.open(fileName, ios::app);

		if (!fout)
		{
			std::cerr << "Помилка збереження файлу...\n";
			exit(1);
		}

		fout << name << ' ' << x << ' ' << y << ' ' << a * 2 << ' ' << b * 2 << '\n';
		fout.close();
	}

	void Elipse::Load(int index)
	{
		string temp;
		int count = -1;

		ifstream fin;
		fin.open(fileName, ios::in);

		if (!fin)
		{
			std::cerr << "Помилка читання файлу...\n";
			exit(1);
		}

		if (fin.is_open())
		{
			do
			{
				count++;
				if (count == index)
					fin >> this->name >> this->x >> this->y >> this->a >> this->b;

				getline(fin, temp);

			} while (count != index);
		}

		fin.close();
	}
}