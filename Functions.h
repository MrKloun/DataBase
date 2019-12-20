#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <string>

setlocale(LC_ALL, "RU"); // вчключение руссого языка
system("color F0"); // смена цвета консоли

using namespace std;

const char* File = "Base.bin";

const string st = "ID\tИМЯ\tПОЛ\t  ВОЗРАСТ\n\n";

const int Areal = 1000; // выделенная память

struct Man
{
	int id; // для каждого человека уникален (единовременно не сущ-т 2х одинаковых ID) и неизменен до уничтожения записи
	string name; // имя
	string age; // возраст
	string pol; // пол
};

void Lin() // красивая прямая линия
{
	int i;
	for (i = 0; i < 80; i++)
		cout << "_";
	cout << endl;
}

int str(string str) // перевод из string в int (может работать некорректно, если в string не только цифры)
{
	int res = 0;
	for (char i : str) 
	{
		res *= 10;
		res += int(i) - 48;
	}
	return res;
}

void PrInf(Man man)
{
	int L(0), l(Areal - 1), i, K(man.id), k(0);
	int C = str(man.age);

	if (man.name != "0")
	{
		while (l != 0)
		{
			l = l / 10;
			L++;
		}
		if (K == 0)
			K = 1;
		while (K != 0)
		{
			K = K/10;
			k++;
		}
		for (i = 0; i < (L - k); i++)
			cout << "0";
		cout << man.id << ")\t" << man.name;
		if (man.pol == "m")
			cout << "\tМуж\t   ";
		else if (man.pol == "w")
			cout << "\tЖен\t   ";
		else
			cout << "\tНеизвестен ";
		if (((C % 10 == 2)or(C % 10 == 3)or(C % 10 == 4)) and (C / 10 != 1))
			cout << man.age << " года;" << endl;
		else if ((C % 10 == 1) and (C / 10 != 1))
			cout << man.age << " год;" << endl;
		else 
			cout << man.age << " лет;" << endl;
	}
}
#endif