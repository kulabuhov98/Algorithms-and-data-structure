#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>

/* 
*
* Автор: Кулабухов Александр Максимович, ЗИТ-21
* Дата: 24.05.2022
* 
*/

using namespace std;

int main () {
	system ("chcp 1251");
	
	int array[50], amount, count, remains, i;
	int minimum = 0;
	
	cout << "Введите количество элементов массива (Максимум 50 элементов): ";
	cin >> count;
	
	cout << "Сформированный массив:" << endl;
	for (i = 0; i < count; i++) {
		array[i] = rand()%100;
		cout << "array[" << i << "] = " << array[i] << endl;
	}
	
	for (i = 1; i < count; i++) {
		if (array[i] < array[minimum]) {
			minimum = i;
		}
	}
	cout << "Минимальный элемент массива: array[" << minimum << "] = " << array[minimum] << endl;
	
	remains = amount = 0;
	if (count > 10) {
		for (i = 0; i < 10; i++) {
			amount = amount + array[i];
			if (array[i] % 2) remains++;
		}
		cout << "Сумма первых 10 элементов массива = " << amount << endl;
		cout << "Количество первых 10 нечетных элементов массива = " << remains << endl;
	}

	system("pause");	
	return 0;
}
