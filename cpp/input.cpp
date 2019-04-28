#include <iostream>
#include <string>
using namespace std;

void print(int a, int b, int c, int d) {
	cout << "Printing int: " << endl  << a << endl << b << endl << c << endl << d << endl;
}

void print(float  a, float b, float  c, float  d) {
	cout << "Printing float: " << endl << a << endl << b << endl << c << endl << d << endl;
}

void print(double a, double b, double c, double d) {
	cout << "Printing double: " << endl  << a << endl << b << endl << c << endl << d << endl;
}



int main(){
	cin >> a >> b >> c >> d;
	print(a, b, c, d);

return 0;
}
