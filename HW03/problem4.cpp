#include <iostream>
using namespace std;

void swapNumbers(int* a, int* b) {
    int temp = *a; 
    *a = *b;       
    *b = temp;     
}

int main() {
    int num1, num2;

    cout << "Enter an integer: ";
    cin >> num1;

    cout << "Enter another integer: ";
    cin >> num2;

    swapNumbers(&num1, &num2); 
    cout << "Swap" << endl;
    cout << "First number: " << num1 << endl;
    cout << "Second number: " << num2 << endl;

    return 0;
}
