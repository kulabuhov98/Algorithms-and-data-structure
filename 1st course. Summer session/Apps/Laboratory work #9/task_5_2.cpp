#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>

/* 
*
* Вариант 5. Номер зачетной книжки: 21-677.
* Составить две программы, которые реализуют алгоритмы простой сортировки "пузырьком"
* и быстрой сортировки. Исходные данные задавать с помощью датчика случайных чисел.
* 
* Сортирока: Быстрая сортировка
*
* Автор: Кулабухов Александр Максимович, ЗИТ-21
* Дата: 27.06.2022
 */

using namespace std;

/* Алгоритм быстрой сортировки */
int quickSorting(int *array, int arraySize) {
	int i = 0;
	int j = arraySize - 1;
	int mid = array[arraySize / 2];
	do {
		while(array[i] < mid) {
		    i++;
		}
		while(array[j] > mid) {
            j--;
        }
		if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            i++;
            j--;
        }
	} while (i <= j);
	
	if (j > 0) {
		quickSorting(array, j + 1);
	}
	if (i < arraySize) {
		quickSorting(&array[i], arraySize - i);
	}
}

int main () {
	system ("chcp 1251");
	
	int arraySize; /* Количество элементов массива */
	
	cout << "Введите количество элементов массива: " << endl; /* Сообщение пользователю */
	cin >> arraySize; /* Количество элементов массива */
	
	int array[arraySize]; /* Инициализация одномерного массива */
	
	cout << "Одномерный массив из " << arraySize << " случайных чисел:" << endl; /* Сообщение пользователю */
	for (int i = 0; i < arraySize; i++) { /* Цикл по столбцам */
		array[i] = rand()%100; /* Заполнение одномерного массива случайными числами в пределах до 100 */
		cout << array[i] << "\t"; /* Сообщение пользователю */
	}
	
	quickSorting(array, arraySize); /* Алгоритм быстрой сортировки */
	
	cout << "\nБыстрая сортировка:" << endl; /* Сообщение пользователю */
	for (int i = 0; i < arraySize; i++) { /* Цикл по столбцам */
		cout << array[i] << "\t"; /* Сообщение пользователю */
	}
	
	system("pause");	
	return 0;
}
