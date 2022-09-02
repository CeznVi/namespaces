#pragma once


namespace math
{
	using std::cout;
	using std::endl;
	using std::cin;

	class Fraction
	{
	private:
		//���������
		int numer;
		//���������
		int denom;

		//��������� ������ �� 2 ��� �������
		bool canDiv2(int num)
		{
			if (num % 2 == 0)
				return true;
			else
				return false;
		}

		//��������� ������ �� 3 ��� �������
		bool canDiv3(int num)
		{
			if (num % 3 == 0)
				return true;
			else
				return false;
		}

		//��������� ��������� ���������� �����
		bool �anCut()
		{
			if (canDiv2(this->numer) && canDiv2(this->denom))
				return true;
			else if (canDiv3(this->numer) && canDiv3(this->denom))
				return true;
			else
				return false;
		}

		////����� ���������� �����
		void �ut()
		{
			while (this->�anCut())
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
		//����������� (���� ��'��� ���� ������ - �� ��� �����������)
		Fraction() : Fraction(0, 0) {}

		//�����������
		Fraction(int numUp, int numDown = 1)
		{
			setNumer(numUp);
			setDenom(numDown);
		}

		//����������� ���������
		Fraction(const Fraction& obj)
		{
			setNumer(obj.numer);
			setDenom(obj.denom);
		}

		//������ ����������
		void setNumer(int numUp)
		{
			numer = numUp;
		}

		//������ ����������
		void setDenom(int numDown)
		{
			if (numDown == 0)
				denom = 1;
			else
				denom = numDown;
		}

		//���������� ��������� ����� (==)
		bool isEqual(const Fraction& d)
		{
			float num1 = static_cast<float>(this->numer) / this->denom;
			float num2 = static_cast<float>(d.numer) / d.denom;
			return (num2 == num1) ? true : false;
		}

		//���������� ��������� ����� (<)
		bool isBig(const Fraction& d)
		{
			float num1 = static_cast<float>(this->numer) / this->denom;
			float num2 = static_cast<float>(d.numer) / d.denom;
			return (num2 > num1) ? true : false;
		}

		//���������� ��������� ����� (>)
		bool isLittle(const Fraction& d)
		{
			float num1 = static_cast<float>(this->numer) / this->denom;
			float num2 = static_cast<float>(d.numer) / d.denom;
			return (num2 < num1) ? true : false;
		}

		//����� ��������� ������, ������� ������������ ���
		Fraction add(const Fraction& d)
		{
			Fraction temp;
			temp.numer = ((d.denom) * (this->numer)) + ((d.numer) * (this->denom));
			temp.denom = (d.denom * this->denom);
			temp.�ut();
			return temp;
		}

		//����� �������� ������, ������� ������������ ���
		Fraction dif(const Fraction& d)
		{
			Fraction temp;
			temp.numer = ((d.denom) * (this->numer)) - ((d.numer) * (this->denom));
			temp.denom = (d.denom * this->denom);
			temp.�ut();
			return temp;
		}

		//����� �������� �����, ������� ������������ ���
		Fraction mult(const Fraction& d)
		{
			Fraction temp;
			temp.numer = (d.numer * this->numer);
			temp.denom = (d.denom * this->denom);
			temp.�ut();
			return temp;
		}

		//����� ������ �����, ������� ������������ ���
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
			temp.�ut();
			return temp;
		}

		//����� ��������� �����, ������� ������ ���
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

		//����� ��������� �����, ������� ������ ���
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

		//����� ��������� �����, �������� (== || !=)
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

		////���������� �� ���������� �����
		//���������� ��������� �����
		Fraction& operator++()
		{
			numer += denom;
			return *this;
		}
		//����������� ��������� �����
		Fraction& operator++(int)
		{
			Fraction temp{ *this };
			numer += denom;
			return temp;
		}
		//����������� ��������� �����
		Fraction& operator--(int)
		{
			Fraction temp{ *this };
			numer -= denom;
			return temp;
		}
		//���������� ��������� �����
		Fraction& operator--()
		{
			numer -= denom;
			return *this;
		}

		////������ ��������� �����(+����������)
		//����� ��������� ����� (���� + ���� = ����)
		Fraction operator+(Fraction& d)
		{
			return this->add(d);
		}
		//����� ��������� ����� (���� + ��� = ����)
		Fraction operator+(const int d)
		{
			return this->add(d);
		}
		//����� ��������� ����� ( ��� + ���� = ����)
		//�������� � ����� ����� ����������� ����� ������� � ����� �������

		////������ �������� �����(+����������)
		//����� �������� ����� (���� - ���� = ����)
		Fraction operator-(Fraction& d)
		{
			return this->dif(d);
		}
		//����� �������� ����� (���� - ��� = ����)
		Fraction operator-(const int d)
		{
			return this->dif(d);
		}
		//����� �������� ����� ( ��� - ���� = ����)
		//�������� � ����� ����� ����������� ����� ������� � ����� �������

		////������ �������� �����(+����������)
		//����� �������� ����� (���� * ���� = ����)
		Fraction operator*(Fraction& d)
		{
			return this->mult(d);
		}
		//����� �������� ����� (���� * ��� = ����)
		Fraction operator*(const int d)
		{
			return this->mult(d);
		}
		//����� �������� ����� ( ��� * ���� = ����)
		//�������� � ����� ����� ����������� ����� ������� � ����� �������

		////������ ������ �����(+����������)
		//����� ������ ����� (���� / ���� = ����)
		Fraction operator/(Fraction& d)
		{
			return this->div(d);
		}
		//����� ������ ����� (���� / ��� = ����)
		Fraction operator/(const int d)
		{
			return this->div(d);
		}
		//����� ������ ����� ( ��� / ���� = ����)
		//�������� � ����� ����� ����������� ����� ������� � ����� �������

		////������ ��������� �����(+����������)
		//��������� ������ ����� ( ���� == ���� )
		bool operator==(Fraction& d)
		{
			return this->isEqual(d);
		}
		//��������� ������ ����� ( int == ���� )
		bool operator==(const int d)
		{
			return this->isEqual(d);
		}
		//��������� �������� ����� ( ���� == ���� )
		bool operator!=(Fraction& d)
		{
			return this->isEqual(d);
		}
		//��������� �������� ����� ( int == ���� )
		bool operator!=(const int d)
		{
			return this->isEqual(d);
		}

		//��������� < ����� ( ���� < ���� )
		bool operator<(Fraction& d)
		{
			return this->isBig(d);
		}
		//��������� < ����� ( int < ���� )
		bool operator<(const int d)
		{
			return this->isBig(d);
		}
		//��������� > ����� ( ���� > ���� )
		bool operator>(Fraction& d)
		{
			return this->isLittle(d);
		}
		//��������� > ����� ( int > ���� )
		bool operator>(const int d)
		{
			return this->isLittle(d);
		}

		//������ (������ ���)
		void print()
		{
			if (this->denom == 1)
				std::cout << numer << '\n';
			else
				std::cout << numer << '/' << denom << '\n';
		}
	};

	//�-��� ���������� ��������� ���������
	Fraction operator+(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.add(d);
	}

	//�-��� ���������� ��������� ��������
	Fraction operator-(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.dif(d);
	}

	//�-��� ���������� ��������� ��������
	Fraction operator*(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.mult(d);
	}

	//�-��� ���������� ��������� ������
	Fraction operator/(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.div(d);
	}

	//�-��� ��������� ������ 
	bool operator==(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.isEqual(d);
	}

	//�-��� ��������� �������� 
	bool operator!=(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.isEqual(d);
	}

	//�-��� ��������� < 
	bool operator<(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.isBig(d);
	}

	//�-��� ��������� > 
	bool operator>(int num, Fraction& d)
	{
		Fraction temp;
		temp.setNumer(num);
		return temp.isLittle(d);
	}

}