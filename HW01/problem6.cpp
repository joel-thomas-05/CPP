#include <iostream>
using namespace std;

void numbersInTheMiddle(int a, int b) {
	if (a >= b) {
	cout << "Try again: b has to be bigger than a." << endl;
	return;
	}
	for (int i = a; i <= b; i++) {
	    cout << i;
		
	    if (i == b) {
            	cout << endl;   
            } else {
            	 cout << " ";   
            }
	}
}

int main() {
	int a, b;
	cout << "Please enter two numbers: " << endl;
	cin >> a >> b;
	
	numbersInTheMiddle(a, b);
	return 0;
}
