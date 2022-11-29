#include <iostream>
#include <math.h>
using namespace std;

void checkValidInput() {
	if (cin.fail())
	{
		throw "Некорректное значение переменной";
	}
}

void checkValidParams(int n) {
	if (n <= 0)
	{
		throw "Введите корректное значение!";
	}
}

double calculate(int n, double x) {
	double result, p;
	if (x <= 0)
	{
		result = 0;
		for (int i = 0; i < n; i++)
		{
			p = 0;
			p = pow(x - i, 2);
			result += p;
		}
	}
	else
	{
		result = 1;
		for (int i = 1; i < n; i++)
		{
			p = 1;
			for (int j = 1; j < n - 1; j++)
			{
				p *= x - i - j;
			}
			result *= p;
		}
	}
	return result;
}


int main()
{
	setlocale(LC_ALL, "UKRAINIAN");
	double x;
	int n;

	try
	{
		cout << "Введите n > 0, n = ";
		cin >> n;
		checkValidInput();
		checkValidParams(n);

		cout << "Введите x = ";
		cin >> x;
		checkValidInput();

		cout << "x = " << x << ";    y = " << calculate(n, x) << endl;
	}
	catch (const char* ex) {
		cout << ex << endl;
		return -1;
	}
	catch (...)
	{
		cout << "Неизвестная ошибка" << endl;
		return -2;
	}
}
