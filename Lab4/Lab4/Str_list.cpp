/*������� ��������� � ������ student, ���������� ��������� ����:
�	�������, ���, ��������;
�	����� ������;
�	������������ �� 5 ��������� (������ ������).
�������� ���������, ����������� ��������� ��������:
�	���� � ���������� ������ � ������, ��������� �� �������� 10 ��������� ���� student, 
������ ������� ����������� �������� ����, ����� ����� ���� �� ������� ��� 10 ���������;
����� ��������� ����� ������������� �������� ������� �� ����������� ������ ������;
�	����� � ������� ������� � ���������, � ����� ������� ����� ���� ���������, ���������� � ������, 
���� ������� ���� �������� ������ 4.0;
�	���� ����� ��������� ���, ������� ��������������� ���������;
�	����������� ������ ������ ���������, ������ ������� ������������ ���������� ������;
�������� ��������� ����� �������, ����� ����������� ��������������� ������ �� ������� ����� 
(������� ������ �������� ����� ��������, ������� ������ ������ �������� � ����� ������� ���������).
*/
#include <windows.h>
#include <iostream>
using namespace std;

struct student {
	char* name = new char[128];
	char* surName = new char[128];
	char* middleName = new char[128];
	int grade[5];
	int number;
	double sr = 0;
};

int main()
{
	setlocale(0, "");
	student *sts = new student[10];
	long int i = 0;

	char a[10];
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> sts[i].name >> sts[i].surName >> sts[i].middleName;
		cin >> sts[i].number;
		for (int j = 0; j < 5; j++) {
			cin >> sts[i].grade[j];
			sts[i].sr += sts[i].grade[j];
		}
		sts[i].sr /= 5;

	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (sts[j].number > sts[j + 1].number)
				swap(sts[j], sts[j + 1]);
		}
	}
	bool isCheck = 0;
	for (int i = 0; i < n; i++)
	{
		if (sts[i].sr > 4)
		{
			isCheck = 1;
			cout << sts[i].name << " " << sts[i].surName << " " << sts[i].middleName << " " << sts[i].number << " ";
			for (int j = 0; j < 5; j++)
				cout << sts[i].grade[j] << " ";
			cout << endl;
		}
	}
	if (isCheck == 0)
		cout << "vse studenti zavalili";

	return 0;
}
