#include <iostream>
#include <fstream>
using namespace std;

int get_choice()
{
	char* choice = new char[256];
	cin >> choice;
	return atoi(choice);
}
bool checkingTheInteger(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			return false;
		}
	}
	return true;
}
bool chekingTheFloat(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '.' )
		{
			return false;
		}
	}
	return true;
}
int get_Int()
{
	while (1)
	{
		char* input = new char[256];
		cout << "Введите целочисленное значение"<<endl;
		cin >> input;

		if (checkingTheInteger(input))
			return atoi(input);
		else
			cout << "Неверный ввод! Попробуйте снова" << endl;
	}
}
float get_Float()
{
	while (1)
	{
		char* input = new char[256];
		cout << "Введите значение с плавающей точкой" << endl;
		cin >> input;

		if (chekingTheFloat(input))
		{
			return atof(input);
		}
		else
			cout << "Неверный ввод! Попробуйте снова" << endl;
	
	}
}
bool get_Bool()
{
	while (1)
	{
		char* input = new char[256];
		cout << "Введите значение логической переменной" << endl;
		cin >> input;

		if (checkingTheInteger(input))
		{
			int bOol = atoi(input);
			if (bOol != 0)

				return true;
			else
				return false;
		}
		else
			cout << "Неверный ввод! Попробуйте снова" << endl;

	}
}
int get_NumberStruct()
{
	char* input = new char[255];
	cout << "Введите номер структуры"<<endl;
	cin >> input;

	if (checkingTheInteger(input))
		return atoi(input);
	else
		cout << "Неверный ввод! Попробуйте снова" << endl;
}
void outputConsol(char* buf, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << buf[i];
	}
}
void outputFile(char* buffer, int length)
{
	ofstream ofile("result.txt");
	for (int i = 0; i < (length); i++)
	{
		ofile << buffer[i];
	}
	ofile.close();
}
union Value
{
	int intValue;
	float floatValue;
	bool boolValue;
};

enum Identifier { Int = 1, Float, Bool };

class Base
{
public:
	virtual bool equals(Base* current) = 0;
	virtual char* toString(char *buffer, int &i) = 0;
	virtual int getType() { return -1; }

	virtual ~Base()
	{
		delete this;
	}
};
class Element : public Base
{
	struct ElementDate
	{
		Value unionValue;
		Identifier choice;
	};
	ElementDate elementDate;
public:
	bool equals(Base* inst)
	{
		if (this->getType() != inst->getType())
			return false;
		else
		{
			Element* newInst = new Element;
			newInst = (Element*)inst;
			if (newInst->elementDate.unionValue.intValue == this->elementDate.unionValue.intValue)
				return true;
			else
				return false;
		}
	}
	char* toString(char *buffer, int &i)
	{
		switch (this->elementDate.choice)
		{
		case 1:
		{
			char* tempBuf = new char[256];
			_itoa_s(this->elementDate.unionValue.intValue, tempBuf, 256, 10);
			for (int l = 0; l < strlen(tempBuf); l++)
			{
				buffer[i] = tempBuf[l];
				i++;
			}
		}
		break;

		case 2:
		{
			char* tempBuf = new char[256];
			sprintf_s(tempBuf, 256, "%f", this->elementDate.unionValue.floatValue);

			int newStrlen = strlen(tempBuf), y = strlen(tempBuf) - 1;
			for (y; y > 0; y--)
			{
				if (tempBuf[y] == '0')
				{
					newStrlen--;
				}
				else
				{
					break;
				}
			}
			for (int l = 0; l < newStrlen; l++)
			{
				buffer[i] = tempBuf[l];
				i++;
			}
			delete[] tempBuf;
		}
		break;

		case 3:
		{
			if (this->elementDate.unionValue.boolValue)
			{
					buffer[i] = 't';
				buffer[i + 1] = 'r';
				buffer[i + 2] = 'u';
				buffer[i + 3] = 'e';
				i += 4;
			}
			else
			{
					buffer[i] = 'f';
				buffer[i + 1] = 'a';
				buffer[i + 2] = 'l';
				buffer[i + 3] = 's';
				buffer[i + 4] = 'e';
				i += 5;
			}
		}
		}
		return buffer;
	}


	int getType()
	{
		return 1;
	}
	Value get_Value(Identifier type)
	{
		type = elementDate.choice;
		return elementDate.unionValue;
	}
	void setInt(int i)
	{
		elementDate.unionValue.intValue = i;
		elementDate.choice = Identifier::Int;
	}
	void setFloat(float i)
	{
		elementDate.unionValue.floatValue = i;
		elementDate.choice = Identifier::Float;
	}
	void setBool(bool i)
	{
		elementDate.unionValue.boolValue = i;
		elementDate.choice = Identifier::Bool;
	}
};
class Container : public Base
{
	int j;
	int length;
	Container* parent = nullptr;
	Base** array = new Base*[length];
	void arrayExpansion()
	{
		length *= 2;
		Base** tempArray = new Base*[length];
		for (int i = 0; i < length / 2; i++)
		{
			tempArray[i] = array[i];
		}
		array = tempArray;
		delete[] tempArray;
		delete tempArray;
	}
	int search(Container* container, Base* inst)
	{
		int sum = 0;
		int t = container->getContNum();
		for (int i = 0; i < t; i++)
		{
			if (container->getArray()[i]->getType() != inst->getType())			 
				continue;
			else
			{
				if (!inst->getType())											 
				{
					Container* newInst = new Container, *secInst = new Container;
					newInst = (Container*)inst;
					secInst = (Container*)container->getArray()[i];
					if (newInst != secInst)											
					{
						if (newInst->getContNum() == 0)									
						{
							(secInst->getContNum() == 0) ? sum++ : sum = sum;
						}
						else														
						{
							if (newInst->getContNum() == secInst->getContNum())     
							{
								int tempSum = 0;
								for (int k = 0; k < newInst->getContNum(); k++)
								{
									tempSum += search(secInst, newInst->getArray()[k]);
								}
								if (tempSum == newInst->getContNum())
									sum++;
							}
							else
								continue;
						}
					}
				}
				else															
				{
					Element* newInst = new Element, *secInst = new Element;
					newInst = (Element*)inst;
					secInst = (Element*)container->getArray()[i];
					Identifier type = Int;
					if (newInst->get_Value(type).intValue == secInst->get_Value(type).intValue && newInst != secInst)																									  
					{						     
						sum++;					  
					}
					else
						continue;
					delete newInst, secInst;
				}
			}
		}
		return sum;
	}
	bool addArray(Base*  Inst)
	{
		if (!search(this, Inst))
		{
			if (j < length)
				array[j] = (Base*)Inst;
			else
			{
				arrayExpansion();
				array[j] = (Base*)Inst;
			}
			j++;
		}
		else
		{
			return false;
		}
		return true;
	}
public:
	void addContainer()
	{
		Container* newContainer = new Container;
		if (j < length)
		{
			array[j] = (Base*)newContainer;
			j++;
			newContainer->parent = this;
		}
		else
		{
			arrayExpansion();
			array[j] = (Base*)newContainer;
			j++;
			newContainer->parent = this;
		}
	}
	void addElement(int choice)
	{
		Element* newElem = new Element;
		Base* newInst = (Base*)newElem;
		switch (choice)
		{
		case 1:
			newElem->setInt(get_Int());
			addArray(newInst);
			break;
		case 2:
			newElem->setFloat(get_Float());
			addArray(newInst);
			break;
		case 3:
			newElem->setBool(get_Bool());
			addArray(newInst);
			break;
		}
	}
public:
	
	int getType()
	{
		return 0;
	}
	bool equals(Base* current)
	{
		if (this->getType() != current->getType())
			return false;
		else
		{
			Container* newInst = new Container, *secInst = new Container;
			newInst = (Container*)current;
			secInst = (Container*)this;
			if (newInst->getContNum() == secInst->getContNum())
			{
				int tempSum = 0;
				for (int i = 0; i < newInst->getContNum(); i++)
				{
					tempSum += search(secInst, newInst->getArray()[i]);
				}

				if (tempSum == newInst->getContNum() || newInst == secInst)
					return true;
				else
					return false;
			}
			else
				return false;
			delete newInst, secInst;
		}
	}
	char* toString(char *buffer, int &i)
	{
		buffer[i] = '[';
		i++;
		for (int k = 0; k < j; k++)
		{
			if (k != 0)
			{
				buffer[i] = ',';
				i++;
			}
			if (this->array[k]->getType())
			{
				Element* newInst = (Element*)this->array[k];
				newInst->toString(buffer, i);
			}
			else
			{
				Container* newInst = (Container*)array[k];
				newInst->toString(*&buffer, i);
			}
		}
		buffer[i] = ']';
		i++;
		return buffer;
	}
	int getContNum()
	{
		return j;
	}
	bool moveDown(Container* &current)
	{
		int i = get_NumberStruct() - 1;
		if (i < j)
		{
			if (!array[i]->getType())
			{
				current = (Container*)array[i];
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	bool moveUp(Container* &current)
	{
		if (current->parent != nullptr)
			current = current->parent;
		else
		{
			return false;
		}
		return true;
	}
	Base** getArray()
	{
		return this->array;
	}
	Container()
	{
		j = 0;
		length = 8;
		parent = nullptr;
	}

	~Container()																
	{
		for (int i = 0; i < j; i++)
		{
			delete[] array[i];
		}
		delete[] array;
		delete array;
		delete parent;
	}
};
Base * ChangeTheStructure(Container* &current)
{
	Base * newCurrent = (Base*)current;
	while (true)
	{
		cout << "3) Вывести" << endl << "5) Переместится вниз" << endl << "6) Переместится вверх" << endl << "9) Выбор";
		switch (get_choice())
		{
		case 3:
		{
			char* buf = new char[255];
			int i = 0;
			current->toString(buf, i);
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
			cout << "Введите 0 что бы выбрать текущую структуру или введите конкретный номер структуры";
			cin >> choice2;
			if (choice2)
			{
				newCurrent = current->getArray()[get_NumberStruct() - 1];
				return newCurrent;
			}
			else
			{
				return (Base*)current;
			}
		}
		}
	}
}
int main()
{
	setlocale(0, "");
	Container root;
	Container* current = new Container;
	current = &root;
	while (1)
	{
		cout << "1) Создать контейнир" << endl << "2) Создать элемент" << endl << "3) Вывести" << endl << "4) Проверить равенство" << endl << "5) Переместится вниз" << endl << "6) Переместится вверх" << endl << "0) Выход" << endl;
		switch (get_choice())
		{
		case 1:
			current->addContainer();
			break;
		case 2:
			cout << "Выберите тип данных :"<<endl << "1) целочисленный"<<endl <<"2) с плавающей точкой"<<endl<<"3) логическая"<<endl;
			int choice;
			cin >> choice;
			current->addElement(choice);
			break;
		case 3:
		{
			char* buf = new char[255];
			int i = 0;
			current->toString(buf, i);
			outputConsol(buf, i);
			cout << endl;
			outputFile(buf, i);
			break;
		}
		case 4:
		{
			Base* fstInst = ChangeTheStructure(current);
			Element* newFstInstE = new Element;
			Container* newFstInstC = new Container;

			if (fstInst->getType())
			{
				newFstInstE = (Element*)fstInst;
				if (newFstInstE->equals(ChangeTheStructure(current)))
					cout << "Структуры равны" << endl;
				else
					cout << "Структуры не равны" << endl;;
				delete newFstInstC;
			}
			else
			{
				newFstInstC = (Container*)fstInst;
				if (newFstInstC->equals(ChangeTheStructure(current)))
					cout << "Структуры равны" << endl;
				else
					cout << "Структуры не равны" << endl;;
				delete newFstInstE;
			}
		}
		break;
		case 5:
			if (!current->moveDown(current))
			{
				cout << "Некуда опускаться " << endl;
			}
			break;
		case 6:
			if (!current->moveUp(current))
			{
				cout << "Некуда подниматься" << endl;
			}
			break;
		case 0:
			return 0;
		}
	}
}