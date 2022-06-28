#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>

/* 
* Вариант 5. Номер зачетной книжки: 21-677.
* Разработать алгоритм и программу интерполирующего поиска.
* В качестве исходных данных использовать массив целых чисел, который
* вводится с клавиатуры. Аргумент поиска - число.
*
* Автор: Кулабухов Александр Максимович, ЗИТ-21
* Дата: 27.06.2022
*/

using namespace std;

/* Алгоритм интерполирующего поиска */
int interpolationSearch(int array[], int arraySize, int argumentOfSearch) {
	int low = 0, high = arraySize - 1, mid;
	
	while (array[low] <= argumentOfSearch && array[high] >= argumentOfSearch) {
		mid = low + ((argumentOfSearch-array[low]) * (high-low)) / (array[high] - array[low]);
		if (array[mid] < argumentOfSearch) {
			low = mid + 1;
		} else if (array[mid] > argumentOfSearch) {
			high = mid - 1;
		} else {
			return mid;
		}
	}
	if (array[low] == argumentOfSearch) {
		return low;	
	} else {
		return -1;
	}
}

int main () {
	system ("chcp 1251");
	
	int arraySize, arrayItem, argumentOfSearch; /* Количество элементов массива, Элемент массива, Аргумент интерполирующего поиска */
	
	cout << "Введите количество элементов массива: "; /* Сообщение пользователю */
	cin >> arraySize; /* Количество элементов массива */
	
	int array[arraySize]; /* Инициализация массива */

	for (int i = 0; i < arraySize; i++) { /* Цикл по столбцам */
		cout << "Введите элемент массива: "; /* Сообщение пользователю */
		cin >> arrayItem; /* Элемент массива */
		
		array[i] = arrayItem; /* Заполнение массива элементами пользователями*/
	}
	
	/* Алгоритм простой сортировки "Пузырьком" для корректной работы алгоритма интерполирующего поиска */
	for (int i = 0; i < arraySize - 1; i++) {
		for (int j = 0; j < arraySize - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	
	cout << "Сформированный массив из элементов пользователя:" << endl; /* Сообщение пользователю */
	for (int i = 0; i < arraySize; i++) { /* Цикл по столбцам */
		cout << array[i] << "\t"; /* Сообщение пользователю */
	}
	
	cout << "\nВведите аргумент интерполирующего поиска: " << endl; /* Сообщение пользователю */
	cin >> argumentOfSearch;
	
	if (interpolationSearch(array, arraySize, argumentOfSearch) == -1) {
		cout << "\nАргумент интерполирующего поиска " << argumentOfSearch << " не найден в массиве."<< endl; /* Сообщение пользователю */
	} else {
		cout << "\nАргумент интерполирующего поиска " << argumentOfSearch << " найден в массиве с индексом " << interpolationSearch(array, arraySize, argumentOfSearch) + 1 << "."<< endl; /* Сообщение пользователю */
	}
	
	system("pause");	
	return 0;
}
