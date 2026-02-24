#include <iostream>
using namespace std;


int main() {

    // Part A: using a "for" loop
    for (int i = 1; i <= 100; i++) {
        cout << "Hello World!"  << endl;
    }

    cout << endl;

    // Part B: using a "while" loop
    int j = 1;
    while (j <= 100) {
        cout << "Hello World!"  << endl;
        j++;
    }

    cout << endl;

    // Part C: using a "do-while" loop

    int k = 1;
    do {
        cout << "Hello World!"  << endl;
        k++;
    } while (k <= 100);

    return 0;
}







