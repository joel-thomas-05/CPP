#include <iostream>
using namespace std;

int main() {
    int grade;

    cout << "Enter your score:" << endl;
    cin >> grade;

    if (grade >= 90) {
        cout << "Your grade is A" << endl;
    } else if (grade >= 80) {
        cout << "Your grade is B" << endl;
    } else if (grade >= 70) {
        cout << "Your grade is C" << endl;
    } else if (grade >= 60) {
        cout << "Your grade is D" << endl;
    } else {
        cout << "Your grade is F" << endl;
    }

    return 0;
}
