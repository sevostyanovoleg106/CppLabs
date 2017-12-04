#include <fstream> 
#include <iostream> 
#include <cstring> 
using namespace std;
int main()
{
	 
	setlocale(LC_ALL, "rus");
	char buff[255];
	ifstream fin("INPUT.txt");
	ofstream fout("OUTPUT.txt");
	double dMax;
	char nMax[255];
	int kMax;
	bool isFirst = 0;
	if (!fin.is_open())
		cout << "LOL";
	else
	{
		while (!fin.eof())
		{
			fin.getline(buff, 255);
			char *tgm = buff;
			char *tmp = buff;
				if (buff[0]=='\0')
					break;
			
			char str[255];
			char chr[255];
			int *b = new int[255];
			int z = 0;
			int it = 0;
			int sum = 0;
			while (strchr(tmp, ';'))
			{
					b[it] = atoi(tmp);
					if (b[it] != 0)
					{
						//fout << b[it] << " ";
						it++;
					}
					tmp = strchr(tmp, ';') + 1;
					
					
			}
			
			b[it] = atoi(tmp);
			it++;
			//for (int p = 0; p < it; p++)
			//	fout << b[p] << " ";
			for(int p = 1; p < it; p++)
			{
				sum += b[p] - b[p - 1];
			}
			double sr;
			sr = (double)sum / (it - 1);
			//fout << sr;
			//fout << endl;
			char *pch = strtok(buff, ";");
			int i = 0;
			int k = 0;
			while (i < 3)
			{
				i++;
			   // fout << pch << endl;
				for(int q=0;q<255;q++,k++)
				{
					if (pch[q] == '\0')
						break;

					str[k] = pch[q];
					//fout << str[k];

				}
				
				str[k] = ' ';
				//fout << str[k];
				k++;
				pch = strtok(NULL, ";");
			}
			if (!isFirst)
			{
				dMax = sr;
				for (int t = 0; t < k; t++)
				{
					nMax[t] = str[t];
				}
				kMax = k;
				isFirst = 1;
			}
			else
			{
				if (sr > dMax)
				{

					dMax = sr;

					for (int t = 0; t < k; t++)
					{
						nMax[t] = str[t];
					}
					kMax = k;
				}
			}
			//fout << endl;
			delete[] b;
		}
	}
	fout << dMax << endl;
	for (int i = 0; i < kMax; i++)
		fout << nMax[i];
	fin.close();
	fout.close();
//	system("pause");
	return 0;
}