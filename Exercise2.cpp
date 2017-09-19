

#include "stdafx.h"
#include<iostream>
#include <cmath>
using namespace std;


int main()
{
	double x,a;
	cin >> x;
	cin >> a;
	
		if (x <= 0)
			cout << -a << endl;

		else
		
			if (0 <x && x <= 1)
				cout << a << endl;


			else

		
				if (1 <x && x <= 2)
					cout << "1" << endl;


				else
				
					if (2 <x && x <= 3)
						cout << -2*a << endl;
					
	
    return 0;
}

