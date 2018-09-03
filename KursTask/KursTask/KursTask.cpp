/*
Написать программу, моделирующую управление каталогом в файловой системе. 
Для каждого файла в каталоге содержатся следующие сведения: имя файла, дата создания, количество обращений к файлу.
Программа должна обеспечивать:

создание каталога или файла в выбранном каталоге;+

вывод содержимого каталога (аналог команды dir в cmd);-

удаление файлов, дата создания которых раньше заданной;-

просмотр и редактирование файла;-

выборку файла с наибольшим количеством просмотров;-

Выбор моделируемой функции должен осуществляться с помощью меню. 
Для представления каталога использовать класс «коллекция ключ-значение».
Хранить всю информацию (всю систему каталогов и файлов) в базе данных в виде текстового файла.
*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <cstring>
#include <cstdio>

using namespace std;



char* copyOfstrings(const char* buffer)
{
	char* string = new char[256];
	int i = 0;
	for (i; i < strlen(buffer) + 1; i++)
	{
		string[i] = buffer[i];
	}
	string[i + 1] = '\0';
	return string;
}
char* STRCAT(char* buf, const char* buffer)
{
	char* buff = new char[256];
	int i = 0;
	for (i; i < strlen(buf) + 1; i++)
	{
		if (buf[i] != '\0')
			buff[i] = buf[i];
		else
		{
			break;
		}

	}
	for (int j = 0; j < strlen(buffer); j++, i++)
	{
		buff[i] = buffer[j];
	}
	buff[i] = '\0';
	return buff;
}

class DateTime
{
	int day, month, year, hour, minute, second;
	char* time;
public:
	char* dateToString(SYSTEMTIME st)
	{
		int day = st.wDay;
		char* dayStr = new char[64];
		_itoa_s(day, dayStr, 64, 10);

		int month = st.wMonth;
		char* monthStr = new char[64];
		_itoa_s(month, monthStr, 64, 10);

		int year = st.wYear;
		char* yearStr = new char[64];
		_itoa_s(year, yearStr, 64, 10);

		int hour = st.wHour;
		char* hourStr = new char[64];
		_itoa_s(hour, hourStr, 64, 10);

		int minute = st.wMinute;
		char* minuteStr = new char[64];
		_itoa_s(minute, minuteStr, 64, 10);

		int second = st.wSecond;
		char* secondStr = new char[64];
		_itoa_s(second, secondStr, 64, 10);

		time = copyOfstrings(yearStr);
		time = STRCAT(time, ".");
		time = STRCAT(time, monthStr);
		time = STRCAT(time, ".");
		time = STRCAT(time, dayStr);
		time = STRCAT(time, " ");
		time = STRCAT(time, hourStr);
		time = STRCAT(time, ":");
		time = STRCAT(time, minuteStr);
		time = STRCAT(time, ":");
		time = STRCAT(time, secondStr);
		return time;
	}

};
class Recording
{
	int id;
	int numberOfvisits = 0;
	char* name;
	int parentId;
	SYSTEMTIME st;
	char* date;
	char* type;
public:
	Recording(int id, char* name, unsigned int numberOfvisits, int parentId, char* type, char* date)
	{
		this->id = id;
		this->numberOfvisits = numberOfvisits;
		this->name = name;
		this->parentId = parentId;
		this->date = date;
		this->type = type;
	}
	Recording() {}
	void set_id(int id)
	{
		this->id = id;
	}

	int get_id() { return id; }
	int get_numberOfvisits() { return numberOfvisits; }
	char* get_name() { return  name; }
	int get_parentId() { return parentId; }
	char* get_date() { return date; }
	char* get_type() { return type; }
};
template <class TKey, class TValue>
class CollectionElem
{
public:
	TKey key;
	TValue value;

	CollectionElem(int id, char* name, unsigned int numberOfvisits, int parentId, char* type, char* date)
	{
		value = Recording(id, name, numberOfvisits, parentId, type, date);
		key = id;
	}

	CollectionElem() {}

	void print()
	{
		cout << value.get_type() << "\t" << value.get_name() << "\t" << value.get_numberOfvisits() <<"\t"<<value.get_parentId()<< "\t" << value.get_date() << endl;
	}
};
class FileSystem
{

	CollectionElem<int, Recording> *array;
	int size;
public:
	FileSystem()
	{
		size = 0;
		array = new CollectionElem<int, Recording>();
	}
	void set_size(int size)
	{
		this->size = size;
	}
	void IncreaseArraySize()
	{
		CollectionElem<int, Recording>* newArray = new CollectionElem<int, Recording>[size + 1];
		for (int i = 0; i < size; i++)
			newArray[i] = array[i];
		array = newArray;
	}
	CollectionElem<int, Recording>* get_array()
	{
		return array;
	}
	int get_size()
	{
		return size;
	}

	CollectionElem<int, Recording> searchById(int id, FileSystem &fs)
	{
		for (int i = 0; i < fs.get_size(); i++)
		{
			if (fs.array[i].value.get_id() == id)
				return fs.array[i];
		}
	}

	int searchIdByName(char* name, FileSystem &fs)
	{
		for (int i = 0; i < fs.get_size(); i++)
		{
			if (!strcmp(fs.array[i].value.get_name(), name))
				return fs.array[i].value.get_id();
		}
	}

	FileSystem* getArrayChilds(int id, FileSystem &fs)
	{
		FileSystem *mas = new FileSystem();
		for (int i = 0; i < fs.get_size(); i++)
		{
			if (fs.array[i].value.get_parentId() == id)
			{
				mas->add(fs.array[i].value.get_id(),
					fs.array[i].value.get_name(),
					fs.array[i].value.get_numberOfvisits(),
					fs.array[i].value.get_parentId(),
					fs.array[i].value.get_type(),
					fs.array[i].value.get_date());
			}
		}
		return mas;
	}

	void add(int id, char* name, unsigned int numberOfvisits, int parentId, char* type, char* date)
	{

		IncreaseArraySize();
		array[size] = CollectionElem<int, Recording>(id, name, numberOfvisits, parentId, type, date);
		size++;

	}
	void save()
	{
		ofstream fout("LOL.txt");
		for (int i = 0; i < size; i++)
		{
			fout << array[i].value.get_id() << ";" << array[i].value.get_type() << ";" << array[i].value.get_name() << ";" << array[i].value.get_numberOfvisits() << ";"<< array[i].value.get_parentId() << ";" << array[i].value.get_date() << '\0' << endl;
		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << ". ";
			array[i].print();
		}
	}
	void clear()
	{
		size = 0;
		array = new CollectionElem<int, Recording>();
	}

	int searchId(char* buffer, FileSystem fs)
	{

		int count = 0;
		for (int i = 0; i <= strlen(buffer) ; i++)
		{
			if (buffer[i] == '\\' || buffer[i] == '\0')
				count++;
		}
		char** arr = new char*[count];
		for (int g = 0; g < count; g++)
		{
			arr[g] = new char[256];
		}
		
		int tempIndex = 0;
		int i = 0;
		for (int j = 0; j < count ; j++)
		{
			char*  temp = new char[256];
			for (i; i < strlen(buffer) + 1; i++)
			{
				if (buffer[i] != '\\' || buffer[i] == '\0')
				{
					temp[tempIndex] = buffer[i];
					tempIndex++;
				}
				else
				{
					temp[tempIndex] = '\0';
					tempIndex = 0;
					break;
				}
			}
			i++;
			arr[j] = temp;
		}
		if (count == 1)
			return 0;
		int id = searchIdByName(arr[0], fs);
		FileSystem *childs = new FileSystem();
		for (int f = 1; f < count ; f++)
		{
			childs = getArrayChilds(id, fs);
			for (int j = 0; j < childs->get_size(); j++)
			{
				if (!strcmp(arr[f], childs->array[j].value.get_name()))
				{
					id = searchIdByName(childs->array[j].value.get_name(), *childs);
				}
			}
		}
		return id;
	}

	bool load()
	{
		clear();
		ifstream fout("LOL.txt");
		if (fout.is_open())
		{
			char* buffer = new char[256];
			int flag = 0;
			while (!fout.eof())
			{
				fout.getline(buffer, 256);

				char* parentId = new char[5];
				char* type = new char[1];
				char* name = new char[256];
				char* numberOfvisits = new char[10];
				char* date = new char[20];
				char* id = new char[5];
				if (strcmp(buffer, "") != 0)
				{
					char* temp = new char[80];
					int tempIndex = 0;

					int s = sizeof(buffer);
					int str = strlen(buffer);
					for (int i = 0; i < strlen(buffer) + 1; i++)
					{
						if (buffer[i] != ';')
						{
							temp[tempIndex] = buffer[i];
							tempIndex++;
						}
						else
						{
							temp[tempIndex] = '\0';
							if (flag == 0)
							{
								id = new char[strlen(temp) + 1];
								id = copyOfstrings(temp);
								flag = 1;
								tempIndex = 0;
								continue;
							}
							if (flag == 1)
							{
								type = new char[strlen(temp) + 1];
								type = copyOfstrings(temp);
								flag = 2;
								tempIndex = 0;
								continue;
							}
							if (flag == 2)
							{
								name = new char[strlen(temp) + 1];
								name = copyOfstrings(temp);
								flag = 3;
								tempIndex = 0;
								continue;
							}
							if (flag == 3)
							{
								numberOfvisits = new char[strlen(temp) + 1];
								numberOfvisits = copyOfstrings(temp);
								flag = 4;
								tempIndex = 0;
								continue;
							}
							if (flag == 4)
							{
								parentId = new char[strlen(temp) + 1];
								parentId = copyOfstrings(temp);
								tempIndex = 0;
								continue;
							}
						}
						if (buffer[i] == '\0')
						{
							date = new char[strlen(temp) + 1];
							date = copyOfstrings(temp);
							add(atoi(id), name, atoi(numberOfvisits), atoi(parentId), type, date);
							tempIndex = 0;
							flag = 0;
							break;
						}
					}
				}
			}
			return true;
		}
		else
			cout << "Файл не найден" << endl;

		return false;
	}
};
int main()
{

	setlocale(0, "");
	FileSystem *fileSystem = new FileSystem();
	FileSystem fs = *fileSystem;
	DateTime *dt = new DateTime;
	SYSTEMTIME st;
	bool result = fs.load();
	if (!result)
	{
		ofstream fout("LOL.txt");
		char* name;
		name = copyOfstrings("R:");
		GetSystemTime(&st);
		fs.add(0, name, 0, -1, copyOfstrings("d"), dt->dateToString(st));
		fs.save();
	}

	int choose;
	while (1)
	{
		char *name = new char[256];
		char *road = new char[256];
		int parentId = 0;
		cout << "1 - файл" << endl << "2 - папка" << endl <<"3 - вывести"<<endl<< "4 - сохранить и выйти" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:

			cout << "Введите путь: ";
			cin >> road;
			parentId = fs.searchId(road, fs);
			cout << "Введите имя файла" << endl;
			cin >> name;
			GetSystemTime(&st);
			fs.add(fs.get_size(), name, 0, parentId, copyOfstrings("f"), dt->dateToString(st));
			fs.save();
			break;
		case 2:
			cout << "Введите путь: ";
			cin >> road;
			parentId = fs.searchId(road, fs);
			cout << "Введите имя папки" << endl;
			cin >> name;
			GetSystemTime(&st);
			fs.add(fs.get_size(), name, 0, parentId, copyOfstrings("d"), dt->dateToString(st));
			fs.save();
			break;
		case 3:
			fs.print();
			break;
		case 4:
			return 0;
		}
		
	}

	system("pause");
	return 0;
}
