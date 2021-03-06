#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>

/* 
* Задание 3.2.2. Номер зачетной книжки: 21-677.
* Составить программу, которая формирует одномерный массив вводом с 
* клавиатуры и находит среднее арифметическое элементов массива с p1 по p2
*
* Автор: Кулабухов Александр Максимович, ЗИТ-21
* Дата: 10.05.2022
*/

using namespace std;

int main () {
	system ("chcp 1251");
	
	/* Одномерный массив, вспомогательная переменная i, диапазон для нахождения среднего арифметического элементов массива */
	int array[10], i, p1, p2;
	/* Количество элементов одномерного массива, результат выполнения алгоритма */
	float count, result = 0;
	
	cout << "Введите количество элементов одномерного массива (максимум 10): ";
	cin >> count;
	
	/* Формирование одномерного массива с определенным количеством элементов */
	for (i = 0; i < count; i++) {
		cout << "Введите " << i << " значение одномерного массива: ";
		cin >> array[i];
	}
	
	cout << "Введите диапазон (с использованием индексов) для нахождения среднего арифметического элементов массива:" << endl;
	cin >> p1; 
	cin >> p2;
	
	/* Общая сумма элементов алгоритма в заданном диапазоне */
	for (i = p1; i <= p2; i++) {
		result = result + array[i];
	}
	
	/* Вывод результата выполнения алгоритма и нахождения среднего арифметического элементов массива */
	cout << "Среднее арифметическое элементов массива с " << p1 << " по " << p2 << " = " << result / i << endl;

	system("pause");	
	return 0;
}
