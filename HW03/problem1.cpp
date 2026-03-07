#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int* ptr2 = &arr[1]; 
    int* ptr4 = &arr[3]; 

    int temp = *ptr2; 
    *ptr2 = *ptr4;    
    *ptr4 = temp;     

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
