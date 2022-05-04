// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string.h>

using namespace std;

int dlina1(char*);
int dlina2(char*);
int dlina3(char*);
void copy(char*, char*);
int sravn(char*, char*);
char* comkat(char*, char*);

int main(void) {

	setlocale(LC_ALL, "Russian");

	char str1[] = "qwerty", str2[] = "1234567890";
	cout << "длина str1 = " << dlina1(str1) << ", str2 = " << dlina1(str2) << endl;
	cout << "длина str1 = " << dlina2(str1) << ", str2 = " << dlina2(str2) << endl;
	cout << "длина str1 = " << dlina3(str1) << ", str2 = " << dlina3(str2) << endl;

	copy(str1, str2);
	cout << "результат копирования: str1 = " << str1 << ", str2 = " << str2 << endl;
	cout << "результат сравнения: str1 = " << str1 << ", str2 = " << str2 << " out: " << sravn(str1, str2) << endl;
	cout << "результат обьединения: str1 = " << str1 << ", str2 = " << str2 << " out: " << comkat(str1, str2) << endl;

	cout << "################################################################################################" << endl;

	char* s1 = (char*)malloc(sizeof("qwerty"));
	char* s2 = (char*)malloc(sizeof("1234567890"));
	strcpy(s1, "qwerty");
	strcpy(s2, "1234567890");

	cout << "длина str1 = " << dlina1(s1) << ", str2 = " << dlina1(s2) << endl;
	cout << "длина str1 = " << dlina2(s1) << ", str2 = " << dlina2(s2) << endl;
	cout << "длина str1 = " << dlina3(s1) << ", str2 = " << dlina3(s2) << endl;

	copy(s1, s2);
	cout << "результат копирования: str1 = " << s1 << ", str2 = " << s2 << endl;
	cout << "результат сравнения: str1 = " << s1 << ", str2 = " << s2 << " out: " << sravn(s1, s2) << endl;
	cout << "результат обьединения: str1 = " << s1 << ", str2 = " << s2 << " out: " << comkat(s1, s2) << endl;

	cout << "################################################################################################" << endl;

	char* sc1 = (char*)calloc(sizeof("qwerty"), sizeof(char));
	char* sc2 = (char*)calloc(sizeof("1234567890"), sizeof(char));
	strcpy(sc1, "qwerty");
	strcpy(sc2, "1234567890");

	cout << "длина str1 = " << dlina1(sc1) << ", str2 = " << dlina1(sc2) << endl;
	cout << "длина str1 = " << dlina2(sc1) << ", str2 = " << dlina2(sc2) << endl;
	cout << "длина str1 = " << dlina3(sc1) << ", str2 = " << dlina3(sc2) << endl;

	copy(sc1, sc2);
	cout << "результат копирования: str1 = " << sc1 << ", str2 = " << sc2 << endl;
	cout << "результат сравнения: str1 = " << sc1 << ", str2 = " << sc2 << " out: " << sravn(sc1, sc2) << endl;
	cout << "результат обьединения: str1 = " << sc1 << ", str2 = " << sc2 << " out: " << comkat(sc1, sc2) << endl;

	cout << "################################################################################################" << endl;

	char Array[][80] = {
		"STRING 1",
		"STRING 2",
		"STRING 3",
		"STRING 4",
	};

	cout << "длина str1 = " << dlina1(Array[0]) << ", str2 = " << dlina1(Array[1]) << endl;

	for (auto s : Array) {
		cout << s << endl;
	}
	return 0;
}

int dlina1(char* s) {

	int i = 0;
	while (1) {
		if (s[i] != 0) {
			i++;
			continue;
		}
		else {
			break;
		}
	}
	return i;

}

int dlina2(char* s) {

	char* end = 0;
	int i = 0;
	while (1) {
		if (s[i] == 0) {
			end = &s[i];
			break;
		}
		i++;
	}
	return end - s;

}

int dlina3(char* s) {

	char str[strlen(s)];
	strcpy(str, s);

	return sizeof(str) / sizeof(char);

}

void copy(char* s1, char* s2) {

	int len = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);
	for (int i = 0; i <= len; i++) {
		s1[i] = s2[i];

	}

}

int sravn(char* s1, char* s2) {

	int len1 = dlina1(s1), len2 = dlina1(s2);
	if (len1 - len2 != 0) {
		return len1 - len2;
	}
	else {
		for (int i = 0; i < len1; i++) {
			if (s1[i] == s2[i]) continue;
			else return -1;
		}
		return 0;

	}

}

char* comkat(char* s1, char* s2) {

	int len = dlina1(s1) + dlina2(s2);
	char* str = (char*)malloc(len);
	int i = 0;
	for (int j = 0; j < dlina1(s1); j++) {
		str[i] = s1[j];
		i++;
	}

	for (int j = 0; j < dlina1(s2); j++) {
		str[i] = s2[j];
		i++;
	}

	return str;

}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
