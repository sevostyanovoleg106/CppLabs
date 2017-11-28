/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в
несколько строк.За один просмотр файла, без использования сортировки
сформировать список этих чисел, упорядоченный по неубыванию(каждый следующий
элемент списка больше или равен предыдущему).Значения полученного списка
занести в текстовый файл OUTPUT.TXT.*/
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char buff[255];
	ifstream fin("INPUT.txt");
	ofstream fout("OUTPUT.txt");
	int* b = new int[255];
	int z = 0;
	if (!fin.is_open())
		cout << "LOL";
	else
	{
		fin.getline(buff, 255);
		char* tmp = buff;


		for (int i = 0; i < 255; i++)
		{

			b[z] = atoi(tmp);
			for (int k = 1; k <= z; k++)
			{
				for (int j = k; j > 0 && b[j - 1]>b[j]; j--)
				{
					swap(b[j - 1], b[j]);
				}
			}
			z++;

			if (strchr(tmp, ' ') == (char*)0)
			{
				break;
			}
			else
			{
				tmp = strchr(tmp, ' ') + 1;

			}
		}


	}

	for (int i = 0; i < z; i++)
	{
		fout << b[i] << " ";
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}