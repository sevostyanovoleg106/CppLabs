#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <cstring>

using namespace std;

enum Identifier { file = 0, catalog };

char* copyOFlines(char* buf, char* buffer = new char[256])
{
	for (int i = 0; i < strlen(buffer); i++)
	{
		buf[i] = buffer[i];
	}
	return buf;
}
char* sumOFlines(char* buf, const char* buffer = new char[256])
{
	int index = 0;
	for (int i = 0; i < strlen(buf); i++)
	{
		if (buf[i] != '\0')
			continue;
		else
			index = i;
	}
	for (index; index < strlen(buffer); index++)
	{
		buf[index] = buffer[index];
	}
	return buf;
}
int get_NumberStruct()
{
	char* input = new char[2];
	cout << "Введите номер структуры" << endl;
	cin >> input;
	return atoi(input);
}
template<class Tkey, class Tvalue>
class Collection
{
	struct Element
	{
		Tkey key;
		Tvalue value;
	};
	int length = 0;
	int index = 0;
	void arrayExpansion(Collection array)
	{
		int newLenght = length;
		Collection* newArray = new Collection[newLenght];
		for (int i = 0; i < lenght; i++)
		{
			newArray[i] = array[i];
		}
		array = newArray;
		for (int i = 0; i < newLenght; i++)
		{
			delete newArray[i];
		}
		length = newLenght;
	}
	void set_key(Tkey key)
	{
		this->key = key;
	}
	void set_value(Tvalue value)
	{
		this->value = value;
	}
	
public:
	int get_identifier()
	{
		return -1;
	}
	Collection()
	{
		index = length = 0;
		key = value = NULL;
	}
	int search(Collection array)
	{
		for (int i = 0; i < index; i++)
		{
			if (array[i]->get_key() == key)
				return i;
		}
		return -1;
	}
	
	int get_index()
	{
		return this->index;
	}
	Tkey get_key()
	{
		return this->key;
	}
	Tvalue get_value()
	{
		return this->value;
	}
	friend ostream& operator << (ostream& out, const Collection& index)
	{
		for (int i = 0; i < index.get_index(); i++)
		{
			out << index.get_key(i) << ',' << index.get_value(i) << endl;
		}
		return out;
	}

	friend istream& operator>> (istream& in, Collection& index)
	{
		while (in.peek() != '\n')
		{
			Tkey key;
			Tvalue* value = new Tvalue;
			in >> key;
			in >> *value;
			index.add(key, *value);
		}
		return in;
	}
	bool add(Tkey key, Tvalue value, Collection array)
	{
		if (search(array[index]->key) == -1)
		{
			if (index >= length)
			{
				arrayExpansion();
			}

			set_key(key);
			set_value(value);
			index++;
			return true;
		}
		return false;
	}
	bool del(Tkey key, Collection array)
	{
		if (index > 0)
		{
			int idx = search(array[index]->key);
			if (idx != -1)
			{
				for (int i = idx; i < index; i++)
				{
					array[i] = array[i + 1];
				}
				index--;
				return true;
			}
			else
				return false;
		}
		return false;
	}
};
class File
{
	struct FiletData
	{
		char* name;
		int day, month, year, hour, minute, second;
		int numberOFvisits = 0;
	};
	FiletData filetData;
public:
	
	File()
	{

	}
	int get_identifier()
	{
		return file;
	}
	File(SYSTEMTIME &st)
	{
		filetData.day = st.wDay;
		filetData.month = st.wMonth;
		filetData.year = st.wYear;
		filetData.hour = st.wHour + 5;
		filetData.minute = st.wMinute;
		filetData.second = st.wSecond;
	}
	void set_name(char* name) { this->filetData.name = name; }
	void set_numberOFvisits(int numberOFvisits){this->filetData.numberOFvisits = numberOFvisits;}
	char* get_name() { return filetData.name; }
	int get_day(){return filetData.day;}
	int get_month(){return filetData.month;}
	int get_year(){return filetData.year;}
	int get_numberOFvisits(){return filetData.numberOFvisits;}
	int get_hour(){return filetData.hour;}
	int get_minute(){return filetData.minute;}
	int get_second(){return filetData.minute;}

	char* toString(File &f, char* buffer= new char[256] )
	{
		copyOFlines(buffer, (char*)f.get_name());
		sumOFlines(buffer, " ");
		sumOFlines(buffer, (char*)f.get_day());
		sumOFlines(buffer, ".");
		sumOFlines(buffer, (char*)f.get_month());
		sumOFlines(buffer, ".");
		sumOFlines(buffer, (char*)f.get_year());
		sumOFlines(buffer, "      Time: ");
		sumOFlines(buffer, (char*)f.get_hour());
		sumOFlines(buffer, ":");
		sumOFlines(buffer, (char*)f.get_minute());
		sumOFlines(buffer, ":");
		sumOFlines(buffer, (char*)f.get_second());
		sumOFlines(buffer, "  Visits: ");
		sumOFlines(buffer, (char*)f.get_numberOFvisits());
		
		return buffer;
	}
};
class Catalog 
{
	char* name;
	int quantity = 0;
	int length = 8;
	int j = 0;
	Catalog* parent = nullptr;
	Collection<int, int>** arr = new Collection<int, int>*[length];
	void arrayExpansion()
	{
		int newLenght = length;
		Collection<int, int>** newArray = new Collection<int, int>*[length];
		for (int i = 0; i < length; i++)
		{
			newArray[i] = arr[i];
		}
		arr = newArray;
		for (int i = 0; i < newLenght; i++)
		{
			delete &newArray[i];
		}
		length = newLenght;
	}
	void addArray(Collection<int,int>* Inst)
	{
		if (j < length)
		{
			arr[j] = (Collection<int, int>*)Inst;
		}
		else
		{
			arrayExpansion();
			arr[j] = (Collection<int, int>*)Inst;
		}
		j++;
	}
	
public:
	void set_name(char* name)
	{
		this->name = name;
	}
	char* get_name()
	{
		return name;
	}
	int get_identifier()
	{
		return catalog;
	}
	Catalog()
	{
		name = new char[256];
	}
	Collection<int, int>** get_array()
	{
		return this->arr;
	}
	char* toString(  int &i, char* buffer = new char[256])
	{
		buffer[i] = '[';
		i++;
		sumOFlines(buffer, get_name());
		i += strlen(get_name());
		for (int f = 0; f < j; f++)
		{
			if (f != 0)
			{
				buffer[i] = '\n';
				buffer[i] = ' ';
				buffer[i] = ' ';
				i++;
			}
			if (this->arr[f]->get_identifier() == 1)
			{
				File* newInst = (File*)this->arr[f];
				newInst->toString(*newInst,buffer);
			}
			else
			{
				Catalog* newInst = (Catalog*)arr[f];
				newInst->toString( i, *&buffer);
			}
		}
		buffer[i] = ']';
		i++;
		return buffer;
	}
	void addCatalog(char* buff)
	{

		Catalog* newCatalog = new Catalog;
		newCatalog->set_name(buff);
		if (j < length)
		{
			arr[j] = (Collection<int, int>*)newCatalog;
			j++;
		}
		else
		{
			arrayExpansion();
			arr[j] = (Collection<int, int>*)newCatalog;
			j++;
		}
	}
	void addFile()
	{
		File* newFile = new File;
		Collection<int,int>*  newInst = (Collection<int, int>*)newFile;
		addArray(newInst);
	}
	bool moveDown(Catalog* &current)
	{
		int i = get_NumberStruct() - 1;
		if (i < j)
		{
			current = (Catalog*)arr[i];
		}
		else
		{
			return false;
		}
		return true;
	}

	bool moveUp(Catalog* &current)
	{
		if (current->parent != nullptr)
			current = current->parent;
		else
		{
			return false;
		}
		return true;
	}
};
void outputConsol(char* buf, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << buf[i];
	}
}
int get_choice()
{
	char* choice = new char[256];
	cin >> choice;
	return atoi(choice);
}
Collection<int,int>* ChangeTheStructure(Catalog* &current)
{
	Collection<int, int>* newCurrent = (Collection<int, int>*)current;
	while (true)
	{
		cout << endl << "3) Вывести" << endl << "5) Переместится вниз" << endl << "6) Переместится вверх" << endl << "9) Выбор" << endl;
		switch (get_choice())
		{
		case 3:
		{
			char* buf = new char[255];
			int i = 0;
			current->toString(i,buf);
			outputConsol(buf, i);
			break;
		}
		case 5:
			current->moveDown(current);
			break;
		case 6:
			current->moveUp(current);
			break;
		case 9:
		{
			short choice2;
			cout << "Введите 0 что бы выбрать текущую структуру или введите конкретный номер структуры" << endl;
			cin >> choice2;
			if (choice2)
			{
				newCurrent = current->get_array()[get_NumberStruct() - 1];
				return newCurrent;
			}
			else
			{
				return (Collection<int, int>*)current;
			}
		}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SYSTEMTIME st;
	GetSystemTime(&st);
	/*File f(st);*/
	Catalog root;
	Catalog* current = new Catalog;
	current = &root;
	char* buf = new char[255];
	char* nameCatalog = new char[20];
	int i = 0;
	while (1)
	{
		cout << "1) Создать каталог" << endl << "2) Создать файл" << endl << "3) Вывести"  << endl << "4) Переместится вниз" << endl << "5) Переместится вверх" << endl << "0) Выход" << endl;
		switch (get_choice())
		{
		case 1:
			cout << "Введите названеие каталога" << endl;
			cin >> nameCatalog;
			current->addCatalog(nameCatalog);
			break;
		case 2:
			current->addFile();
			break;
		case 3:
			
			current->toString(i,buf);
			outputConsol(buf, i);
			cout << endl;
			//outputFile(buf, i);
			break;
		case 4:
			if (!current->moveDown(current))
			{
				cout << "Некуда опускаться " << endl;
			}
			break;
		case 5:
			if (!current->moveUp(current))
			{
				cout << "Некуда подниматься" << endl;
			}
			break;
		case 0:
			return 0;
		}
	}
	system("pause");
}