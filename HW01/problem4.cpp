#include <iostream>
using namespace std;

double calc(double a, double b) {
	return a * b + 20.51;
}

int main() {
	cout << calc(2, 3) << endl;
	cout << calc(6, 7) << endl;
	cout << calc(100, 4) << endl;
	return 0;
}
