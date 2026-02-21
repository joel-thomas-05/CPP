#include <iostream>
using namespace std;

int calc(int a, int b) {
	return a * b + 200;
}

int main() {
	cout << calc(2, 3) << endl;
	cout << calc(6, 7) << endl;
	cout << calc(100, 4) << endl;
	return 0;
}
