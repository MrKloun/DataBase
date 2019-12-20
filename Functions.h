#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <string>

setlocale(LC_ALL, "RU"); // ���������� ������� �����
system("color F0"); // ����� ����� �������

using namespace std;

const char* File = "Base.bin";

const string st = "ID\t���\t���\t  �������\n\n";

const int Areal = 1000; // ���������� ������

struct Man
{
	int id; // ��� ������� �������� �������� (������������� �� ���-� 2� ���������� ID) � ��������� �� ����������� ������
	string name; // ���
	string age; // �������
	string pol; // ���
};

void Lin() // �������� ������ �����
{
	int i;
	for (i = 0; i < 80; i++)
		cout << "_";
	cout << endl;
}

int str(string str) // ������� �� string � int (����� �������� �����������, ���� � string �� ������ �����)
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
			cout << "\t���\t   ";
		else if (man.pol == "w")
			cout << "\t���\t   ";
		else
			cout << "\t���������� ";
		if (((C % 10 == 2)or(C % 10 == 3)or(C % 10 == 4)) and (C / 10 != 1))
			cout << man.age << " ����;" << endl;
		else if ((C % 10 == 1) and (C / 10 != 1))
			cout << man.age << " ���;" << endl;
		else 
			cout << man.age << " ���;" << endl;
	}
}
#endif