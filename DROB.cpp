#include "stdafx.h"
#include <iostream>
#include  <cmath> 

using namespace std;

 int main()
{
	 
	 double x, y, z;
	 double a=1, b=5;
	 double PI = 3.14159265359;
	 double r, t;

	 cin >> x;
	 cin >> y;
	 cin >> z;
	 r = pow(sin(abs(y+2)), 3);
	 t = pow(sin(x+PI/2), -1);
	 a = ((2 * sin(y + PI / 3)) / (1 / 2 + r)) + t;
	 b = 1 + ((pow(z, 2) / 5) / 3 - pow(z, 2 / 3));
	 cout << a<<endl;
	 cout << b<<endl;




	

     return 0;
