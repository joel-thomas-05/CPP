#include <iostream>
using namespace std;

int main() {
	long long sum = 0;
	int y;

	while (cin >> y) {
		sum += y;
	}

	cout << "Sum: " << sum << endl;
	return 0;
}
