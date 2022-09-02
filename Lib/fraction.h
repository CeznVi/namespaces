#pragma once


namespace math
{
	using std::cout;
	using std::endl;
	using std::cin;

	class Fraction
	{
	private:
		//чисельник
		int numer;
		//знаменник
		int denom;

		//Інспектор ділення на 2 без остатку
		bool canDiv2(int num)
		{
			if (num % 2 == 0)
				return true;
			else
				return false;
		}

		//Інспектор ділення на 3 без остатку
		bool canDiv3(int num)
		{
			if (num % 3 == 0)
				return true;
			else
				return false;
		}

		//Інспектор можливого скорочення дробу
		bool сanCut()
		{
			if (canDiv2(this->numer) && canDiv2(this->denom))
				return true;
			else if (canDiv3(this->numer) && canDiv3(this->denom))
				return true;
			else
				return false;
		}

		////Метод скорочення дробу
		void сut()
		{
			while (this->сanCut())
			{
				if (canDiv2(this->numer) && canDiv2(this->denom))
				{
					this->numer = this->numer / 2;
					this->denom = this->denom / 2;
				}
				else if (canDiv3(this->numer) && canDiv3(this->denom))
				{
					this->numer = this->numer / 3;
					this->denom = this->denom / 3;
				}
				else
					break;
			}
		}

	public:
		//Конструктор (якщо об'єкт буде пустий - то йде делегування)
		Fraction() : Fraction(0, 0) {}

		//Конструктор
		Fraction(int numUp, int numDown = 1)
		{
			setNumer(numUp);
			setDenom(numDown);
		}

		//Конструктор копіювання
		Fraction(const Fraction& obj)
		{
			setNumer(obj.numer);
			setDenom(obj.denom);
		}

		//Сеттер чисельника
		void setNumer(int numUp)
		{
			numer = numUp;
		}

		//Сеттер знаменника
		void setDenom(int numDown)
		{
			if (numDown == 0)
				denom = 1;
			else
				denom = numDown;
		}

		//Інспектори порівняння дробів (==)
		bool isEqual(const Fraction& d)
		{
			float num1 = static_cast<float>(this->numer) / this->denom;
			float num2 = static_cast<float>(d.numer) / d.denom;
			return (num2 == num1) ? true : false;
		}

		//Інспектори порівняння дробів (<)
		bool isBig(const Fraction& d)
		{
			float num1 = static_cast<float>(this->numer) / this->denom;
			float num2 = static_cast<float>(d.numer) / d.denom;
			return (num2 > num1) ? true : false;
		}

		//Інспектори порівняння дробів (>)
		bool isLittle(const Fraction& d)
		{
			float num1 = static_cast<float>(this->numer) / this->denom;
			float num2 = static_cast<float>(d.numer) / d.denom;
			return (num2 < num1) ? true : false;
		}

		//Метод додавання дробей, повертає результуючій дріб
		Fraction add(const Fraction& d)
		{
			Fraction temp;
			temp.numer = ((d.denom) * (this->numer)) + ((d.numer) * (this->denom));
			temp.denom = (d.denom * this->denom);
			temp.сut();
			return temp;
		}

		//Метод віднімання дробей, повертає результуючій дріб
		Fraction dif(const Fraction& d)
		{
			Fraction temp;
			temp.numer = ((d.denom) * (this->numer)) - ((d.numer) * (this->denom));
			temp.denom = (d.denom * this->denom);
			temp.сut();
			return temp;
		}

		//Метод множення дробів, повертає результуючій дріб
		Fraction mult(const Fraction& d)
		{
			Fraction temp;
			temp.numer = (d.numer * this->numer);
			temp.denom = (d.denom * this->denom);
			temp.сut();
			return temp;
		}

		//Метод ділення дробів, повертає результуючій дріб
		Fraction div(const Fraction& d)
		{
			if (d.numer == 0)
			{
				std::cout << "Eror.Cannot be divided by 0 \n";
				return 0;
			}
			Fraction temp;
			temp.numer = this->numer * d.denom;
			temp.denom = this->denom * d.numer;
			temp.сut();
			return temp;
		}

		//Метод порівняння дробів, повертає більший дріб
		Fraction more(const Fraction& d)
		{
			Fraction temp;

			if (this->isBig(d))
			{
				temp.numer = d.numer;
				temp.denom = d.denom;

			}
			else
				temp = 0;
			return temp;
		}

		//Метод порівняння дробів, повертає менший дріб
		Fraction less(const Fraction& d)
		{
			Fraction temp;

			if (this->isBig(d))
			{
				temp.numer = this->numer;
				temp.denom = this->denom;
			}
			else
				temp = 0;

			return temp;
		}

		//Метод порівняння дробів, виводить (== || !=)
		void compare(const Fraction& d)
		{
			if (isEqual(d))
			{
				std::cout << this->numer << '/' << this->denom;
				std::cout << " == " << d.numer << '/' << d.denom << '\n';
			}
			else
			{
				std::cout << this->numer << '/' << this->denom;
				std::cout << " != " << d.numer << '/' << d.denom << '\n';
			}
		}

		////Інкременти та декременти класу
		//Префіксний інкремент класу
		Fraction& operator++()
		{
			numer += denom;
			return *this;
		}
		//Постфіксний інкремент класу
		Fraction& operator++(int)
		{
			Fraction temp{ *this };
			numer += denom;
			return temp;
		}
		//Постфіксний декремент класу
		Fraction& operator--(int)
		{
			Fraction temp{ *this };
			numer -= denom;
			return temp;
		}
		//Префіксний декремент класу
		Fraction& operator--()
		{
			numer -= denom;
			return *this;
		}

		////Методи додавання дробів(+перегрузки)
		//Метод додавання дробів (клас + клас = клас)
		Fraction operator+(Fraction& d)
		{
			return this->add(d);
		}
		//Метод додавання дробів (клас + інт = клас)
		Fraction operator+(const int d)
		{
			return this->add(d);
		}
		//Метод додавання дробів ( інт + клас = клас)
		//винесено з класу через неможливість обійти помилку з двома членами

		////Методи віднімання дробів(+перегрузки)
		//Метод віднімання дробів (клас - клас = клас)
		Fraction operator-(Fraction& d)
		{
			return this->dif(d);
		}
		//Метод віднімання дробів (клас - інт = клас)
		Fraction operator-(const int d)
		{
			return this->dif(d);
		}
		//Метод віднімання дробів ( інт - клас = клас)
		//винесено з класу через неможливість обійти помилку з двома членами

		////Методи множення дробів(+перегрузки)
		//Метод множення дробів (клас * клас = клас)
		Fraction operator*(Fraction& d)
		{
			return this->mult(d);
		}
		//Метод множення дробів (клас * інт = клас)
		Fraction operator*(const int d)
		{
			return this->mult(d);
		}
		//Метод множення дробів ( інт * клас = клас)
		//винесено з класу через неможливість обійти помилку з двома членами

		////Методи ділення дробів(+перегрузки)
		//Метод ділення дробів (клас / клас = клас)
		Fraction operator/(Fraction& d)
		{
			return this->div(d);
		}
		//Метод ділення дробів (клас / інт = клас)
		Fraction operator/(const int d)
		{
			return this->div(d);
		}
		//Метод ділення дробів ( інт / клас = клас)
		//винесено з класу через неможливість обійти помилку з двома членами

		////Методи порівняння дробів(+перегрузки)
		//Інспектор рівності дробів ( клас == клас )
		bool operator==(Fraction& d)
		{
			return this->isEqual(d);
		}
		//Інспектор рівності дробів ( int == клас )
		bool operator==(const int d)
		{
			return this->isEqual(d);
		}
		//Інспектор нерівності дробів ( клас == клас )
		bool operator!=(Fraction& d)
		{
			return this->isEqual(d);
		}
		//Інспектор нерівності дробів ( int == клас )
		bool operator!=(const int d)
		{
			return this->isEqual(d);
		}

		//Інспектор < дробів ( клас < клас )
		bool operator<(Fraction& d)
		{
			return this->isBig(d);
		}
		//Інспектор < дробів ( int < клас )
		bool operator<(const int d)
		{
			return this->isBig(d);
		}
		//Інспектор > дробів ( клас > клас )
		bool operator>(Fraction& d)
		{
			return this->isLittle(d);
		}
		//Інспектор > дробів ( int > клас )
		bool operator>(const int d)
		{
			return this->isLittle(d);
		}

		//Геттер (друкуе дріб)
		void print()
		{
			if (this->denom == 1)
				std::cout << numer << '\n';
			else
				std::cout << numer << '/' << denom << '\n';
		}
	};

	//Ф-ція перегрузки опаратора додавання
	Fraction operator+(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.add(d);
	}

	//Ф-ція перегрузки опаратора віднімання
	Fraction operator-(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.dif(d);
	}

	//Ф-ція перегрузки опаратора множення
	Fraction operator*(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.mult(d);
	}

	//Ф-ція перегрузки опаратора ділення
	Fraction operator/(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.div(d);
	}

	//Ф-ція інспекції рівності 
	bool operator==(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.isEqual(d);
	}

	//Ф-ція інспекції нерівності 
	bool operator!=(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.isEqual(d);
	}

	//Ф-ція інспекції < 
	bool operator<(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.isBig(d);
	}

	//Ф-ція інспекції > 
	bool operator>(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.isLittle(d);
	}

}