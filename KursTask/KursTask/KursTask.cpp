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
	char* string = new char[sizeof(buffer)];
	int i = 0;
	for (i; i < strlen(buffer) + 1; i++)
	{
		string[i] = buffer[i];
	}
	string[i + 1] = '\0';
	return string;
}
char* STRCAT(char* first_string, const char* second_string)
{
	char* tmp = new char[sizeof(first_string) + sizeof(second_string)];
	int i = 0;
	for (i; i < strlen(first_string) + 1; i++)
	{
		if (first_string[i] != '\0')
			tmp[i] = first_string[i];
		else
		{
			break;
		}

	}
	for (int j = 0; j < strlen(second_string); j++, i++)
	{
		tmp[i] = second_string[j];
	}
	tmp[i] = '\0';
	return tmp;
}

class DateTime
{
	short day, month, year, hour, minute, second;
	char* time;
public:
	char* dateToString(SYSTEMTIME st)
	{
		day = st.wDay;
		char* dayStr = new char[64];
		_itoa_s(day, dayStr, 64, 10);

		month = st.wMonth;
		char* monthStr = new char[64];
		_itoa_s(month, monthStr, 64, 10);

		year = st.wYear;
		char* yearStr = new char[64];
		_itoa_s(year, yearStr, 64, 10);

		hour = st.wHour;
		char* hourStr = new char[64];
		_itoa_s(hour, hourStr, 64, 10);

		minute = st.wMinute;
		char* minuteStr = new char[64];
		_itoa_s(minute, minuteStr, 64, 10);

		second = st.wSecond;
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

	int get_id() { return id; }
	int get_numberOfvisits() { return numberOfvisits; }
	char* get_name() { return  name; }
	int get_parentId() { return parentId; }
	char* get_date() { return date; }
	char* get_type() { return type; }
	char* get_body() { return body; }
	friend ostream& operator << (ostream& out, Recording inst)
	{

		out << inst.get_id() << '\t'
			<< inst.get_type() << '\t'
			<< inst.get_name() << '\t'
			<< inst.get_date() << '\t'
			<< inst.get_numberOfvisits();

		return out;
	}
};

template<class Tkey, class Tvalue>
class Collection
{
	class CollectionElem
	{
	public:
		Tkey key;
		Tvalue value;
		CollectionElem() {}
		CollectionElem(Tkey key, Tvalue value)
		{
			this->key = key;
			this->value = value;
		}
	};

	int sizeCollection = 0;
	CollectionElem **array;
	void IncreaseArraySize()
	{
		CollectionElem** newArray = new CollectionElem*[sizeCollection + 1];
		for (int i = 0; i < sizeCollection; i++)
			newArray[i] = array[i];
		array = newArray;
	}
	void DecreaseArraySize()
	{
		CollectionElem** newArray = new CollectionElem*[sizeCollection - 1];
		for (int i = 0; i < sizeCollection - 1; i++)
			newArray[i] = array[i];
		array = newArray;
	}
public:

	Collection()
	{
		sizeCollection = 0;
		array = new CollectionElem*[sizeCollection];
		for (int i = 0; i < sizeCollection; i++)
		{
			array[i] = new CollectionElem();
		}
	}
	int get_sizeCollection()
	{
		return sizeCollection;
	}
	void set_value(Tvalue value, int id)
	{
		array[id]->value = value;
	}
	Tkey get_key(int i)
	{
		return array[i]->key;
	}
	Tvalue get_value(int i)
	{
		return array[i]->value;
	}
	friend ostream& operator << (ostream& out, Collection inst)
	{
		for (int i = 0; i < inst.get_sizeCollection(); i++)
		{
			out << inst.get_value(i) << endl;
		}
		return out;
	}
	friend istream& operator >> (istream& in, Collection& inst)
	{
		while (in.peek() != '\n')
		{
			Tkey key;
			Tvalue* value = new Tvalue;
			in >> key;
			in >> *value;
			inst.Add(key, *value);
		}
		return in;
	}
	void Add(Tkey key, Tvalue value)
	{
		IncreaseArraySize();
		array[sizeCollection] = new CollectionElem(key, value);
		sizeCollection++;
	}
	void Swap(int first, int second)
	{
		CollectionElem *temp = array[first];
		array[first] = array[second];
		array[second] = temp;
	}
	Tkey SearchKey(int indx)
	{
		for (int i = 0; i < sizeCollection; i++)
		{
			if (i == indx)
				return get_key(i);
		}
	}
	void Delete(Tkey key)
	{
		for (int i = 0; i < sizeCollection; i++)
		{
			if (this->SearchKey(i) == key)
			{
				Swap(i, sizeCollection - 1);
				DecreaseArraySize();
				sizeCollection--;
			}
		}
	}
};

class FileSystem
{

	Collection<int, Recording> *coll;
	int fileSystemSize;
public:
	FileSystem()
	{
		fileSystemSize = 0;
		coll = new Collection<int, Recording>;
	}
	FileSystem(const FileSystem& CopyFS)
	{
		this->fileSystemSize = CopyFS.fileSystemSize;
		this->coll = CopyFS.coll;
	}
	int get_fileSystemSize()
	{
		return fileSystemSize;
	}
	void set_fileSystemSize(int fileSystemSize)
	{
		this->fileSystemSize = fileSystemSize;
	}
	FileSystem* getArrayChilds(int id, FileSystem *fs)
	{
		FileSystem *mas = new FileSystem();
		for (int i = 0; i < fs->get_fileSystemSize(); i++)
		{
			if (fs->coll->get_value(i).get_parentId() == id)
			{
				Recording *rec = new Recording(
					fs->coll->get_value(i).get_id(),
					fs->coll->get_value(i).get_name(),
					fs->coll->get_value(i).get_numberOfvisits(),
					fs->coll->get_value(i).get_parentId(),
					fs->coll->get_value(i).get_type(),
					fs->coll->get_value(i).get_date(),
					fs->coll->get_value(i).get_body());

				mas->Add(i, *rec);
			}
		}
		return mas;
	}
	Collection<int, Recording> get_Array()
	{
		return *coll;
	}
	void Add(int id, Recording record)
	{
		coll->Add(id, record);
		fileSystemSize++;
	}
	void Delete(int id)
	{
		coll->Delete(id);
		//fileSystemSize--;
	}
	void Save()
	{
		ofstream fout("Base.txt");
		for (int i = 0; i < fileSystemSize; i++)
		{
			fout << coll->get_value(i).get_id() << ";"
				<< coll->get_value(i).get_type() << ";"
				<< coll->get_value(i).get_name() << ";"
				<< coll->get_value(i).get_numberOfvisits() << ";"
				<< coll->get_value(i).get_parentId() << ";"
				<< coll->get_value(i).get_date() << ";"
				<< coll->get_value(i).get_body() << '\0'
				<< endl;
		}
	}
	int searchIdByName(char* name)
	{
		for (int i = 0; i < this->fileSystemSize; i++)
		{
			if (!strcmp(this->coll->get_value(i).get_name(), name))
				return this->coll->get_value(i).get_id();
		}
	}
	int searchId(char* buffer)
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
		int id = searchIdByName(arr[0]);
		FileSystem *childs = new FileSystem();
		for (int f = 1; f < count; f++)
		{
			childs = getArrayChilds(id, this);
			for (int j = 0; j < childs->fileSystemSize; j++)
			{
				if (!strcmp(arr[f], childs->coll->get_value(j).get_name()))
				{
					id = searchIdByName(childs->coll->get_value(j).get_name());
				}
			}
		}
		return id;
	}
	bool Load()
	{
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
							this->coll->Add(fileSystemSize, *rec);
							fileSystemSize++;
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
	Recording* MaxAttendance()
	{
		Recording *tmp = new Recording;
		for (int i = 0; i < this->get_fileSystemSize(); i++)
		{
			if (this->get_Array().get_value(i).get_numberOfvisits() > tmp->get_numberOfvisits())
				*tmp = this->get_Array().get_value(i);
		}
		return tmp;
	}
};
int main()
{
	setlocale(0, "");
	DateTime *dt = new DateTime;
	SYSTEMTIME st;
	FileSystem *fs = new FileSystem;
	Recording *tmp;
	FileSystem *fstmp = new FileSystem;
	bool result = fs->Load();
	if (!result)
	{
		ofstream fout("Base.txt");
		char* name;
		name = copyOfstrings("R:");
		GetSystemTime(&st);
		tmp = new Recording(0, name, 0, -1, copyOfstrings("d"), dt->dateToString(st), copyOfstrings(""));
		fs->Add(0, *tmp);
		fs->Save();
	}
	while (1)
	{
		int choice;

		cout << "1) Создать файл" << endl
			<< "2) Создать папку" << endl
			<< "3) Выбор файла с максимальной посещаемостью" << endl
			<< "4) Вывести всю файловую систему" << endl
			<< "5) Открыть" << endl << "6) Удалить" << endl
			<< "7) Сохранить и выйти" << endl;
		cin >> choice;
		char* name = new char[256];
		char* road = new char[256];
		int parentId = 0;
		int deleteElem;
		int choice1;
		char *body = new char[256];
		char *date = new char[256];
		int size;
		switch (choice)
		{
		case 1:
			cout << "Введите путь: ";
			cin >> road;
			parentId = fs->searchId(road);
			cout << "Введите имя файла: ";
			cin >> name;
			GetSystemTime(&st);
			tmp = new Recording(fs->get_fileSystemSize(), copyOfstrings(name), 0, parentId, copyOfstrings("f"), dt->dateToString(st), copyOfstrings(""));
			fs->Add(fs->get_fileSystemSize(), *tmp);
			fs->Save();
			break;
		case 2:
			cout << "Введите путь: ";
			cin >> road;
			parentId = fs->searchId(road);
			cout << "Введите имя папки: ";
			cin >> name;
			GetSystemTime(&st);
			tmp = new Recording(fs->get_fileSystemSize(), copyOfstrings(name), 0, parentId, copyOfstrings("d"), dt->dateToString(st), copyOfstrings(""));
			fs->Add(fs->get_fileSystemSize(), *tmp);
			fs->Save();
			break;
		case 3:
			cout << fs->MaxAttendance();
			break;
		case 4:
			cout << "ID" << '\t' << "Тип" << '\t' << "Имя" << '\t' << "Дата" << '\t' << '\t' << '\t' << "Кол-во посещений" << endl;
			cout << fs->get_Array() << endl;
			break;
		case 5:
			cout << "Введите путь: ";
			cin >> road;
			parentId = fs->searchId(road);
			if (!strcmp(fs->get_Array().get_value(parentId).get_type(), "d"))
			{

				fstmp = fs->getArrayChilds(parentId, fs);
				cout << fstmp->get_Array() << endl;
			}
			else
			{
				cout << "Содержимое файла: ";
				cout << fs->get_Array().get_value(parentId).get_body() << endl;

				cout << "Отредактировать содержимое?" << endl << "1 - Да" << endl << "2 - Нет" << endl;
				cin >> choice1;
				if (choice1 == 1)
				{
					cin >> body;
					tmp = new Recording(
						fs->get_Array().get_value(parentId).get_id(),
						fs->get_Array().get_value(parentId).get_name(),
						fs->get_Array().get_value(parentId).get_numberOfvisits() + 1,
						fs->get_Array().get_value(parentId).get_parentId(),
						fs->get_Array().get_value(parentId).get_type(),
						fs->get_Array().get_value(parentId).get_date(),
						body);
					fs->get_Array().set_value(*tmp, parentId);
					fs->Save();
				}
				else
				{
					tmp = new Recording(
						fs->get_Array().get_value(parentId).get_id(),
						fs->get_Array().get_value(parentId).get_name(),
						fs->get_Array().get_value(parentId).get_numberOfvisits() + 1,
						fs->get_Array().get_value(parentId).get_parentId(),
						fs->get_Array().get_value(parentId).get_type(),
						fs->get_Array().get_value(parentId).get_date(),
						fs->get_Array().get_value(parentId).get_body());
					fs->get_Array().set_value(*tmp, parentId);
					fs->Save();
				}
			}
			break;
		case 6:
			cout << "Введите путь к папке, в которой хотите удалить все элементы раньше заданной даты" << endl;
			cin >> road;
			parentId = fs->searchId(road);
			if (!strcmp(fs->get_Array().get_value(parentId).get_type(), "d"))
			{
				fstmp = fs->getArrayChilds(parentId, fs);
				cout << "Введите дату в формате гггг.мм.дд_чч:мм:сс" << endl;
				cin >> date;
				size = fstmp->get_fileSystemSize();
				for (int i = 0; i < size; i++)
				{
					choice1 = strcmp(fstmp->get_Array().get_value(i).get_date(), date);
					if (choice1 < 0)
					{
						fs->Delete(fstmp->get_Array().get_value(i).get_id());
						size--;
					}

				}
			}
			fs->Save();
			break;
		case 7:
			fs->Save();
			return 0;
		}
	}
}
