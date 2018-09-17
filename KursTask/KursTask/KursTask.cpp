/*
Написать программу, моделирующую управление каталогом в файловой системе.
Для каждого файла в каталоге содержатся следующие сведения: имя файла, дата создания, количество обращений к файлу.
Программа должна обеспечивать:

создание каталога или файла в выбранном каталоге;+

вывод содержимого каталога (аналог команды dir в cmd);+

удаление файлов, дата создания которых раньше заданной;-

просмотр и редактирование файла;+

выборку файла с наибольшим количеством просмотров;+

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
		time = STRCAT(time, "_");
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
	char* body;
public:
	Recording(int id, char* name, unsigned int numberOfvisits, int parentId, char* type, char* date, char* body)
	{
		this->id = id;
		this->numberOfvisits = numberOfvisits;
		this->name = name;
		this->parentId = parentId;
		this->date = date;
		this->type = type;
		this->body = body;
	}
	Recording(const Recording& CopyR)
	{
		this->id = CopyR.id;
		this->numberOfvisits = CopyR.numberOfvisits;
		this->name = CopyR.name;
		this->parentId = CopyR.parentId;
		this->date = CopyR.date;
		this->type = CopyR.type;
		this->body = CopyR.body;
	}
	Recording() {}

	void set_id(int id) { this->id = id; }
	int get_id() { return id; }
	int get_numberOfvisits() { return numberOfvisits; }
	char* get_name() { return  name; }
	int get_parentId() { return parentId; }
	char* get_date() { return date; }
	char* get_type() { return type; }
	char* get_body() { return body; }
	void set_body(char* body) { this->body = body; }
};
template <class TKey, class TValue>
class CollectionElem
{
	TKey key;
	TValue value;
public:

	CollectionElem(TKey key, TValue value)
	{
		this->value = value;
		this->key = key;
	}
	CollectionElem(const CollectionElem& CopyCE)
	{
		this->value = CopyCE.value;
		this->key = CopyCE.key;
	}
	CollectionElem() {}
	TValue get_value() { return value; }
	TKey get_key() { return key; }
	void set_key(TKey key) { this->key = key; }
	void set_value(TValue value) { this->value = value; }
	void print()
	{
		cout << value.get_type() << "\t" << value.get_name() << "\t" << value.get_numberOfvisits() <<  "\t\t\t" << value.get_date() << endl;
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
	FileSystem(int size, CollectionElem<int, Recording> *array)
	{
		this->size = size;
		this->array = array;
	}
	FileSystem(const FileSystem& CopyFS)
	{
		size = CopyFS.size;
		array = CopyFS.array;
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
	void DecreaseArraySize()
	{
		CollectionElem<int, Recording>* newArray = new CollectionElem<int, Recording>[size - 1];
		for (int i = 0; i < size -1 ;i++)
			newArray[i] = array[i];
		array = newArray;
	}
	void Swap(int first, int second)
	{
		CollectionElem<int, Recording> temp = array[first];
		array[first] = array[second];
		array[second] = temp;
	}
	CollectionElem<int, Recording>* get_array()
	{
		return array;
	}
	int get_size()
	{
		return size;
	}

	CollectionElem<int, Recording> searchById(int id)
	{

		for (int i = 0; i < this->get_size(); i++)
		{
			if (this->array[i].get_value().get_id() == id)
				return this->array[i];
		}
	}
	int searchIdByName(char* name, FileSystem &fs)
	{
		for (int i = 0; i < fs.get_size(); i++)
		{
			if (!strcmp(fs.array[i].get_value().get_name(), name))
				return fs.array[i].get_value().get_id();
		}
	}

	FileSystem* getArrayChilds(int id, FileSystem &fs)
	{
		FileSystem *mas = new FileSystem();
		for (int i = 0; i < fs.get_size(); i++)
		{
			if (fs.array[i].get_value().get_parentId() == id)
			{
				Recording *rec = new Recording(
					fs.array[i].get_value().get_id(),
					fs.array[i].get_value().get_name(),
					fs.array[i].get_value().get_numberOfvisits(),
					fs.array[i].get_value().get_parentId(),
					fs.array[i].get_value().get_type(),
					fs.array[i].get_value().get_date(),
					fs.array[i].get_value().get_body());

				mas->add(*rec);
			}
		}
		return mas;
	}

	void add(Recording& rec)
	{
		IncreaseArraySize();
		array[size] = CollectionElem<int, Recording>(rec.get_id(), rec);
		size++;
	}
	void save()
	{
		ofstream fout("Base.txt");
		for (int i = 0; i < size; i++)
		{
			fout << array[i].get_value().get_id() << ";"
				<< array[i].get_value().get_type() << ";"
				<< array[i].get_value().get_name() << ";"
				<< array[i].get_value().get_numberOfvisits() << ";"
				<< array[i].get_value().get_parentId() << ";"
				<< array[i].get_value().get_date() << ";"
				<< array[i].get_value().get_body() << '\0'
				<< endl;
		}
	}
	void print()
	{
		cout << "ID" << " " << "Тип" << "\t" << "Имя" << "\t" << "Кол-во просмотров" << "\t" << "Дата" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << array[i].get_value().get_id() << ". ";
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
		for (int i = 0; i <= strlen(buffer); i++)
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
		for (int j = 0; j < count; j++)
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
		for (int f = 1; f < count; f++)
		{
			childs = getArrayChilds(id, fs);
			for (int j = 0; j < childs->get_size(); j++)
			{
				if (!strcmp(arr[f], childs->array[j].get_value().get_name()))
				{
					id = searchIdByName(childs->array[j].get_value().get_name(), *childs);
				}
			}
		}
		return id;
	}

	bool load()
	{
		clear();
		ifstream fout("Base.txt");
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
				char* body = new char[256];
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
								flag = 5;
								tempIndex = 0;
								continue;
							}
							if (flag == 5)
							{

								date = new char[strlen(temp) + 1];
								date = copyOfstrings(temp);
								tempIndex = 0;
								continue;
							}
						}
						if (buffer[i] == '\0')
						{
							body = new char[strlen(temp) + 1];
							body = copyOfstrings(temp);
							Recording *rec = new Recording(atoi(id), name, atoi(numberOfvisits), atoi(parentId), type, date, body);
							add(*rec);
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

	CollectionElem<int, Recording>* MaxAttendance()
	{
		CollectionElem<int, Recording> *temp = new CollectionElem<int, Recording>();
		for (int i = 1; i < this->get_size() - 1; i++)
		{
			if (this->get_array()[i].get_value().get_numberOfvisits() > temp->get_value().get_numberOfvisits())
				*temp = this->get_array()[i];
		}
		return temp;
	}
	void Delete(int id)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->get_array()[i].get_value().get_id() == id )
			{
				Swap(i, size - 1);
				DecreaseArraySize();
				size--;
			}
		}
	}
};
int main()
{
	setlocale(0, "");
	FileSystem *fileSystem = new FileSystem();
	FileSystem fs = *fileSystem;
	FileSystem *mas = new FileSystem[100];
	DateTime *dt = new DateTime;
	SYSTEMTIME st;
	Recording *rec;
	CollectionElem<int, Recording> *colll;
	bool result = fs.load();
	if (!result)
	{
		ofstream fout("Base.txt");
		char* name;
		name = copyOfstrings("R:");
		GetSystemTime(&st);
		rec = new Recording(0, name, 0, -1, copyOfstrings("d"), dt->dateToString(st), copyOfstrings(""));
		fs.add(*rec);
		fs.save();
	}
	int choose;
	int choose1;
	while (1)
	{
		char *name = new char[256];
		char *road = new char[256];
		int parentId = 0;
		char* body = new char[256];
		char* date = new char[256];
		cout << "1 - файл" << endl << "2 - папка" << endl << "3 - открыть" << endl << "4 - вывести" << endl << "5 - определить файл с наибольшим кол-во просмотров" << endl << "6 - удалить" <<endl<< "7 - сохранить и выйти" << endl;
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
			rec = new Recording(fs.get_size(), name, 0, parentId, copyOfstrings("f"), dt->dateToString(st), copyOfstrings(""));
			fs.add(*rec);
			fs.save();
			break;
		case 2:
			cout << "Введите путь: ";
			cin >> road;
			parentId = fs.searchId(road, fs);
			cout << "Введите имя папки" << endl;
			cin >> name;
			GetSystemTime(&st);
			rec = new Recording(fs.get_size(), name, 0, parentId, copyOfstrings("d"), dt->dateToString(st), copyOfstrings(""));
			fs.add(*rec);
			fs.save();
			break;
		case 3:
			cout << "Введите путь: ";
			cin >> road;
			parentId = fs.searchId(road, fs);
			if (!strcmp(fs.searchById(parentId).get_value().get_type(), "d"))
			{
				mas = fs.getArrayChilds(parentId, fs);
				mas->print();
			}
			else
			{
				cout << "Содержимое файла: ";
				cout << fs.searchById(parentId).get_value().get_body() << endl;

				cout << "Отредактировать содержимое?" << endl << "1 - Да" << endl << "2 - Нет" << endl;
				cin >> choose1;
				switch (choose1)
				{
				case 1:
					cin >> body;
					rec = new Recording(
						fs.searchById(parentId).get_value().get_id(),
						fs.searchById(parentId).get_value().get_name(),
						fs.searchById(parentId).get_value().get_numberOfvisits() + 1,
						fs.searchById(parentId).get_value().get_parentId(),
						fs.searchById(parentId).get_value().get_type(),
						fs.searchById(parentId).get_value().get_date(),
						body);
					fs.get_array()[parentId].set_value(*rec);
					fs.save();
					break;
				case 2:
					rec = new Recording(
						fs.searchById(parentId).get_value().get_id(),
						fs.searchById(parentId).get_value().get_name(),
						fs.searchById(parentId).get_value().get_numberOfvisits() + 1,
						fs.searchById(parentId).get_value().get_parentId(),
						fs.searchById(parentId).get_value().get_type(),
						fs.searchById(parentId).get_value().get_date(),
						fs.searchById(parentId).get_value().get_body());
					fs.get_array()[parentId].set_value(*rec);
					fs.save();
					break;
				}
			}
			break;
		case 4:
			fs.print();
			break;
		case 5:
			fs.MaxAttendance()->print();
			break;
		case 6:
			cout << "Введите путь к папке, в которой хотите удалить все элементы раньше заданной даты" << endl;
			cin >> road;
			parentId = fs.searchId(road, fs);
			if (!strcmp(fs.searchById(parentId).get_value().get_type(), "d"))
			{
				mas = fs.getArrayChilds(parentId, fs);
				cout << "Введите дату в формате гггг.мм.дд_чч:мм:сс" << endl;
				cin >> date;
				choose1 = mas->get_size();
				for (int i = 0; i < choose1; i++)
				{
					choose = strcmp(mas->get_array()[i].get_value().get_date(), date);
					if (choose < 0)
					{
						fs.Delete(mas->get_array()[i].get_value().get_id());
						choose1--;
					}
						
				}
			}
			fs.save();
			break;
		case 7:
			fs.save();
			return 0;
		}

	}

	system("pause");
	return 0;
}
