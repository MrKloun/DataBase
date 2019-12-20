#include "Functions.h"

int main()
{	

	int i;
	int A = 0; // реальный размер массива
	
	Man AVec[Areal]; // данный массив

	Rus();

	/*setlocale(LC_ALL, "RU"); // вчключение руссого языка
	system("color F0"); // смена цвета консоли*/

	ofstream fen(File, ios::app); // создание файла (если его нет) 
	fen.close();
		
	ifstream fin(File); // открытие файла для чтения

	while (!(fin.peek() == EOF)) // пока не конец файла
	{
		if (A > Areal - 1)
		{
			cout << "Ошибка: в файле " << File << " содержится больше эл-тов чем позволено массиву!" << endl;
			fin.close();
			system("PAUSE");
			return 2; // код 2 - слишком большой файл
		}

		fin >> AVec[A].id;

		if (fin.fail()) // в файле не число
		{
			cout << "Ошибка: некорректный ID; файл поврежден!" << endl;
			cout << A << endl;
			fin.close(); // закрыть файл
			system("pause");
			return 3; // код 3 - в файле не число
		}

		fin >> AVec[A].name;	
		fin >> AVec[A].age;	
		fin >> AVec[A].pol;

		A++;
	}
		
	fin.close();																		// окончание работы с файлом

	if (A == 0)
		cout << "База данных пока пуста!" << endl;
	
	bool Y(true); // логическая переменная выхода из цикла
	while (Y)
	{
		string dey; // перемнная - номер действия над базой данных
		string del; // переменная отчистки базы данных
		int ID; // переменная ID

		cout << "\nВведите номер команды:\n\n1) поиск записи по ID;\n2) поиск записи по имени;\n3) редактирование записи;\n"
			<<"4) добавление записи;\n5) удаление записи;\n6) удаление всех записей;\n7) Вывод базы данных на экран;\n"
			<<"8) список незанятых ID;\n0) сохранение и выход.\n\nВвод: "; // указание дей-я

		cin >> dey;

		if (dey == "3")																	// редактирование существующей записи
		{
			cout << "\nВведите ID записи, которую хотите изменить: ";
			cin >> ID;
			if (ID > A - 1)
				cout << "\nОШИБКА: данного ID не существует!\n";
			else
			{

					cout << endl;
					for (i = 0; i < A; i++) // вывод старой записи
						if (ID == AVec[i].id)
							PrInf(AVec[i]);

					//ввод новой записи
					cout << "\nВведите новое имя:\t\t\t\t";
					cin >> AVec[ID].name;

					cout << "Введите новый пол (w - женщина, m - мужчина):\t";
					cin >> AVec[ID].pol;

					cout << "Введите новый возраст:\t\t\t\t";
					cin >> AVec[ID].age;

					cout << "\nДанные успешно изменены!\n";
			}
		}
		else if (dey == "1")															 // поиск существующей записи по ID
		{

			cout << "\nВведите ID записи, которую хотите просмотреть: ";
			cin >> ID;
			cout << endl;
			if ((ID > A - 1) or (AVec[ID].name == "0"))
				cout << "\nОШИБКА: записи с данным ID не существует!\n";
			else
			{
				Lin();
				cout << st;
				PrInf(AVec[ID]); // вывод записи
			}
		}
		else if (dey == "2")															// поиск по имени
		{
			string Name;
			cout << "\nВведите имя: ";
			cin >> Name;
			cout << endl;
			ID = 0;
			Lin();
			cout << st;
			for (i = 0; i < A; i++)
			{
				if (AVec[i].name == Name)
				{
					PrInf(AVec[i]);
					ID++;
				}
			}
			Lin();
			if (ID == 0)
				cout << "\nЗаписи с таким именем в базе данных нет\n";
			else if (((ID % 10 == 2) or (ID % 10 == 3) or (ID % 10 == 4)) and (ID / 10 != 1))
				cout << "\nСуществует " << ID << " записи с именем \"" << Name << "\"\n";
			else if ((ID % 10 == 1) and (ID / 10 != 1))
				cout << "\nСуществует " << ID << " запись с именем \"" << Name << "\"\n";
			else
				cout << "\nСуществует " << ID << " записей c именем \"" << Name << "\"\n";
		}
		else if (dey == "4")															// добавление новой записи
		{
			cout << "\nВы действительно желаете добавить новую запись? (Y - да, N - нет): ";
			cin >> del;
			if (del == "Y")
			{
				ID = -1;
				for (i = 0; i < A; i++) // проверка на пустые строки
				{
					if (AVec[i].name == "0")
					{
						ID = i;
						break;
					}
				}
			}
			else if (del == "N")
			{
				Lin();
				cout << "Новая запись не добавлена";
			}
			else
				cout << "ОШИБКА: Нераспознанная команда!" << endl;
			
			if (ID == -1) // если пустых строк не нашлось
			{
				A++;

				if (A > Areal - 1)
				{
					cout << "\nОШИБКА: невозможно добавление новой записи\n";
					system("PAUSE");
					return 2; // код 2 - слишком большой файл
				}

				cout << "\nВведите данные новой записи:\nИмя:\t\t\t\t";
				cin >> AVec[A - 1].name;
				cout << "Пол (m - мужчина, w - женщина): ";
				cin >> AVec[A - 1].pol;
				cout << "Возраст:\t\t\t";
				cin >> AVec[A - 1].age;
				AVec[A - 1].id = A - 1;
				cout << endl;
				cout << "\nНовая записть успешно добавленна под ID " << A - 1 << endl;	
			}
			else // если нашлась пустая строка
			{
				cout << "\nВведите данные новой записи:\nИмя:\t\t\t\t";
				cin >> AVec[ID].name;
				cout << "Пол (m - мужчина, w - женщина): ";
				cin >> AVec[ID].pol;
				cout << "Возраст:\t\t\t";
				cin >> AVec[ID].age;
				AVec[ID].id = ID;
				cout << endl;
				
				Lin();

				cout << "\nНовая записть успешно добавленна под ID " << ID << endl;
			}
		}
		else if (dey == "5")															// удаление записи
		{
			cout << "\nВведите ID записи, которую хотите удалить: ";
			cin >> ID;
			if ((ID > A - 1) or (AVec[ID].name == "0"))
				cout << "\nОШИБКА: данного ID не существует!\n";
			else 
			{
				cout << "\nВы действительно желаете удалите запись №"<< ID <<"? (Y - да, N - нет): ";
				cin >> del;
				if (del == "Y")
				{
					AVec[ID].name = "0";
					AVec[ID].age = "0";
					AVec[ID].pol = "0";

					cout << "\nЗапись успешно удалена!\n";
				}
				else if (del == "N")
					cout << "Запись не удалена";
				else
					cout << "ОШИБКА: Нераспознанная команда!" << endl;
			}			
		}
		else if (dey == "6")															// удаление всех записей
		{
			cout << "\nВы действительно желаете удалите все записи? (Y - да, N - нет): ";
			cin >> del;
			if (del == "Y")
			{
				for (i = 0; i < A; i++)
				{
					AVec[i].name = "0";
					AVec[i].pol = "0";
					AVec[i].age = "0";
				}
				A = 0;
				Lin();
				cout << "База данных пуста!\n";
			}
			else if (del == "N")
				cout << "Записи не удалены";
			else
				cout << "ОШИБКА: Нераспознанная команда!" << endl;
		}
		else if (dey == "7")															//вывод базы данных
		{
			ID = 0;
			Lin();
			cout << st;
			for (i = 0; i < A; i++)
			{
				PrInf(AVec[i]);
				if (AVec[i].name != "0")
					ID++;
			}
			Lin();
			if (((ID % 10 == 2) or (ID % 10 == 3) or (ID % 10 == 4)) and (ID / 10 != 1))
				cout << "\nСуществует " << ID << " записи\n";
			else if ((ID % 10 == 1) and (ID / 10 != 1))
				cout << "\nСуществует " << ID << " запись\n";
			else
				cout << "\nСуществует " << ID << " записей\n";
		}
		else if (dey == "8")															// незанятые ID
		{	
			ID = 0;
			for (i = 0; i < A; i++)
				if (AVec[i].name == "0")
					ID++;
			Lin();
			if (ID == 0)
				cout << "\nНезанятых ID нет.";
			else if (ID != 0)
			{
				cout << "\nНезанятые ID: ";
				for (i = 0; i < A; i++)
				{
					if ((AVec[i].name == "0") and (ID > 1))
					{
						cout << AVec[i].id << ", ";
						ID--;
					}
					else if (AVec[i].name == "0")
						cout << AVec[i].id << ".";
				}
			}
			cout << endl;

		}
		else if (dey == "0")															// сохранение и выход
			Y = 0; // цикл после набора нуля дальше не продолжается
		else
			cout << "ОШИБКА: Нераспознанная команда!\n";
		Lin();
	}

	while (AVec[A - 1].name == "0")
		A--;

	fen.open(File);

	for (i = 0; i < A; i++) // запись измененной базы данных в файл
	{		
		fen << AVec[i].id << " ";
		fen << AVec[i].name << " ";
		fen << AVec[i].age << " ";
		fen << AVec[i].pol;
		if (i < A - 1)
			fen << "\n";
	}
	cout << endl;
	system("pause");
	return 0;
}