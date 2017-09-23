
#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int x;
	cin>> x;
	int a, b, c, d;
	a = x % 10;
	b = x % 100 / 10;
	c = x % 1000 / 100;
	d = x / 1000;
	if (a == b && a == c)
		cout << "Y" << endl;
		if (a==b && a!=c&& a==d)
			cout << "Y" << endl;
			if (a == b && a != c&& a != d)
				cout << "N" << endl;
				if (a!=b&&a==c&& a==d)
					cout << "Y" << endl;
				if (a != b&&a != c && b != c&& b != d)
					cout << "N" << endl;
				   else cout << "Y" << endl;
						
	
	
	

    return 0;
}

