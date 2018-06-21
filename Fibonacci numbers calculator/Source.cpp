#include <stdio.h>
#include <math.h>
#include <locale.h>

/**
*Находит произвольное число ряда Фибоначчи
*
*@param n порядковый номер ряда Фибоначчи
*@param F значение числа ряда Фибоначчи
*@return F значение числа ряда Фибоначчи
*/
double arbitrary_Fibonacci_number(int n, double  F);

/**
*Находит Следующие числа ряда Фибоначчи
*
*@param n порядковый номер ряда Фибоначчи
*@param F значение числа ряда Фибоначчи
*/
void next_number_of_Fibonacci_series(int n, double  F);

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int n, flag = 1;
	double F = 0;
	for (;;) {
	printf("Введите порядковый номер ряда Фибоначчи: ");
	scanf_s("%i", &n);
	if (n >= 1474) /*Если порядковый номер больше 1474, то программа не способна найти это число Фибоначчи, она будет выводить inf */{
		printf("%i-ое число ряда Фиббоначчи равно inf!\nСледующие числа этого ряда также равны inf!\n", n);
		goto flag;
	}
	if (n >= 0) /*Проверка порядкового номера на правильность*/ {
		printf("Порядковые номера и значения очередных чисел Фибоначчи\n");
		printf("%i-ое число ряда Фиббоначчи равно %g\n", n, arbitrary_Fibonacci_number(n + 1, F));
		printf("Следующие числа этого ряда равны: \n");
		next_number_of_Fibonacci_series(n, F);
	}
	else
		printf("Порядковый номер не может быть отрицательным! Ошибка!\n");
	flag:printf("-------------------------------------------------------\n");
	printf("Введите 1, если хотите продолжить, или  0, если хотите выйти из программы : ");
	scanf_s("%i", &flag);
	if (flag == 0)
		return 0;
	printf("-------------------------------------------------------\n");
	}
}

double arbitrary_Fibonacci_number(int n, double  F)
{
	F = (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
	return F;
}

void next_number_of_Fibonacci_series(int n, double  F)
{
	for (int i = 1; i < 10; i++)
		printf("%i-ое число ряда Фиббоначчи равно %g\n", n + i, arbitrary_Fibonacci_number((n + 1) + i, F));
}