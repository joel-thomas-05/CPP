#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* start = arr;         
    int* end = arr + n - 1;   

    while (start < end) {
        int temp = *start; 
        *start = *end;     
        *end = temp;       

        start++; 
        end--;   
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
