#include <stdio.h>
#include <math.h>
#include <locale.h>

double arbitrary_Fibonacci_number(int n, double  F);

void next_number_of_Fibonacci_series(int n, double  F, double nextF, double prevF);

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int n;
	double F = 0, nextF = 0, prevF = 0;
	printf("Введите порядковый номер ряда Фибоначчи: ");
	scanf_s("%i", &n);
	if (n >= 0) {
		printf("Порядковые номера и значения очередных чисел Фибоначчи\n");
		printf("%i-ое число ряда Фиббоначчи равно %g\n", n, arbitrary_Fibonacci_number(n + 1, F));
		printf("Следующие числа этого ряда равны: \n");
		next_number_of_Fibonacci_series(n, F, nextF, prevF);
	}
	else
		printf("Порядковый номер не может быть отрицательным!\n");
	return 0;
}

double arbitrary_Fibonacci_number(int n, double  F)
{
	F = (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
	return F;
}

void next_number_of_Fibonacci_series(int n, double  F, double nextF, double prevF)
{
	for (int i = 0; i < 10; i++) {
		prevF = arbitrary_Fibonacci_number(n + i, F);
		F = arbitrary_Fibonacci_number((n + 1) + i, F);
		nextF = prevF + F;
		printf("%i-ое число равно %g\n", (n + 1) + i, nextF);
	}
}