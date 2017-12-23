/*Описать структуру с именем student, содержащую следующие поля:
•	фамилия, имя, отчество;
•	номер группы;
•	успеваемость по 5 предметам (массив оценок).
Написать программу, выполняющую следующие действия:
•	ввод с клавиатуры данных в массив, состоящий из максимум 10 элементов типа student,
причем сделать возможность прервать ввод, чтобы можно было не вводить все 10 элементов;
после окончания ввода отсортировать элементы массива по возрастанию номера группы;
•	вывод в консоль фамилий и инициалов, а также номеров групп всех студентов, включенных в массив,
если средний балл студента больше 4.0;
•	если таких студентов нет, вывести соответствующее сообщение;
•	реализовать вторую версию программы, вместо массива использовать двусвязный список;
элементы добавлять таким образом, чтобы сохранялась упорядоченность списка по номерам групп
(вставка нового элемента после элемента, который меньше нового элемента и перед большим элементом).
*/
#include <windows.h>
#include <iostream>
using namespace std;

struct Student {
	char* name = new char[128];
	char* surName = new char[128];
	char* patronymic = new char[128];
	int grade[5];
	int number;
	double sr = 0;
};

struct List
{
	struct cell
	{
		cell *Next;
		cell *Prev;
		Student data;
	};
	cell *Head = nullptr;
	


	void add(Student student)
	{
		cell *temp = new cell;
		temp->data = student;
		temp->Next = NULL;
		temp->Prev = NULL;
		if (Head == NULL)
		{
			Head = temp;
			return;
		}
		temp->Next = Head;
		Head->Prev = temp;
		Head = temp;
	}

	void Data_output()
	{
		cell *temp = Head;
		while (temp != nullptr)
		{
			cout << temp->data.name << " " << temp->data.surName << " " << temp->data.patronymic << " " << temp->data.number << " ";
			for (int j = 0; j < 5; j++)
			{
				cout << temp->data.grade[j] << " ";
				cout << endl;
				temp = temp->Next;
			}
		}
	}
	void clear()
	{
		while (Head != nullptr)
		{
			delete[] Head->data.name;
			delete[] Head->data.surName;
			delete[] Head->data.patronymic;
			cell *temp = Head;
			Head = Head->Next;
			delete temp;
		}
	}
	};

	int main()
	{
		List list;
		setlocale(0, "");
		Student *sts = new Student[10];
		long int i = 0;

		char a[10];
		int n;
		cout << "Введите количество студентов" << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Введите ФИО студента № " << i + 1 << endl;
			cin >> sts[i].name >> sts[i].surName >> sts[i].patronymic;
			cout << "Введите группу студента № " << i + 1 << endl;
			cin >> sts[i].number;
			for (int j = 0; j < 5; j++)
			{
				cout << "Введите оценки за экзамены через пробел" << endl;
				cin >> sts[i].grade[j];
				sts[i].sr += sts[i].grade[j];
			}
			sts[i].sr /= 5;

		}
		Student student;
		list.add(student);
		//алгоритм сортировки списка по номеру группы
		list.Data_output();
		list.clear();
		return 0;
	
}