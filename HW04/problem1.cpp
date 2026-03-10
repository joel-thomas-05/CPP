#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string brand;
        int year;

    public:
        void setYear(int y) {
            year = y;
    }
        void setBrand(string b) {
            brand = b;
        }

        int getYear() {
            return year;
        }

        string getBrand() {
            return brand;
        }

};

int main() {
    Car myCar;
    myCar.setBrand("Toyota");
    myCar.setYear(2020);
    cout << "Car brand: " << myCar.getBrand() << endl;
    cout << "Car year: " << myCar.getYear() << endl;
    return 0;
}
