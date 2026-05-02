#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

string getInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

int getMenuChoice(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);

    try {
        return stoi(input);
    } catch (...) {
        return -1;
    }
}

bool isValidDateFormat(const string& date) {
    if (date.length() != 10) {
        return false;
    }

    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        }

        if (!isdigit(date[i])) {
            return false;
        }
    }

    return true;
}

// Base class: Car
class Car {
protected:
    string carName;
    string carType;
    bool isAvailable;
    string rentStart;
    string rentEnd;

public:
    Car(string name, string type) {
        carName = name;
        carType = type;
        isAvailable = true;
        rentStart = "N/A";
        rentEnd = "N/A";
    }

    virtual ~Car() {}

    string getName() const {
        return carName;
    }

    string getType() const {
        return carType;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    string getRentStart() const {
        return rentStart;
    }

    string getRentEnd() const {
        return rentEnd;
    }

    void rentCar(string startDate, string endDate) {
        isAvailable = false;
        rentStart = startDate;
        rentEnd = endDate;
    }

    void returnCar() {
        isAvailable = true;
        rentStart = "N/A";
        rentEnd = "N/A";
    }

    virtual void displayInfo() const {
        cout << "Name: " << carName
             << " | Type: " << carType
             << " | Status: " << (isAvailable ? "Available" : "Rented")
             << " | Rent Start: " << rentStart
             << " | Rent End: " << rentEnd
             << endl;
    }
};

// Use of Inheritance Below
class Sedan : public Car {
public:
    Sedan(string name) : Car(name, "Sedan") {}

    void displayInfo() const override {
        cout << "[Sedan] ";
        Car::displayInfo();
    }
};

class SUV : public Car {
public:
    SUV(string name) : Car(name, "SUV") {}

    void displayInfo() const override {
        cout << "[SUV] ";
        Car::displayInfo();
    }
};

class Truck : public Car {
public:
    Truck(string name) : Car(name, "Truck") {}

    void displayInfo() const override {
        cout << "[Truck] ";
        Car::displayInfo();
    }
};

class Van : public Car {
public:
    Van(string name) : Car(name, "Van") {}

    void displayInfo() const override {
        cout << "[Van] ";
        Car::displayInfo();
    }
};

class Motorcycle : public Car {
public:
    Motorcycle(string name) : Car(name, "Motorcycle") {}

    void displayInfo() const override {
        cout << "[Motorcycle] ";
        Car::displayInfo();
    }
};

class RentalSystem {
private:
    vector<unique_ptr<Car>> inventory;

    int findCarIndex(const string& name) const {
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i]->getName() == name) {
                return i;
            }
        }
        return -1;
    }

public:
    void registerCar() {
    string name = getInput("\nEnter car name: ");

    if (name.empty()) {
        cout << "Car name cannot be empty.\n";
        return;
    }

    if (findCarIndex(name) != -1) {
        cout << "A car with this name already exists.\n";
        return;
    }

    cout << "\nSelect car type:\n";
    cout << "1. Sedan\n";
    cout << "2. SUV\n";
    cout << "3. Truck\n";
    cout << "4. Van\n";
    cout << "5. Motorcycle\n";

    int typeChoice = getMenuChoice("Enter choice: ");

    cout << "You selected option: " << typeChoice << endl;

    if (typeChoice == 1) {
        inventory.push_back(unique_ptr<Car>(new Sedan(name)));
    } 
    else if (typeChoice == 2) {
        inventory.push_back(unique_ptr<Car>(new SUV(name)));
    } 
    else if (typeChoice == 3) {
        inventory.push_back(unique_ptr<Car>(new Truck(name)));
    } 
    else if (typeChoice == 4) {
        inventory.push_back(unique_ptr<Car>(new Van(name)));
    } 
    else if (typeChoice == 5) {
        inventory.push_back(unique_ptr<Car>(new Motorcycle(name)));
    } 
    else {
        cout << "Invalid car type. Car was not registered.\n";
        return;
    }

    cout << name << " has been registered successfully.\n";
    cout << "Total cars in inventory: " << inventory.size() << endl;
}

    void deregisterCar() {
        string name = getInput("\nEnter the name of the car to deregister: ");
        int index = findCarIndex(name);

        if (index == -1) {
            cout << "Car not found.\n";
            return;
        }

        if (!inventory[index]->getAvailability()) {
            cout << "Cannot deregister a currently rented car.\n";
            return;
        }

        inventory.erase(inventory.begin() + index);
        cout << name << " has been deregistered successfully.\n";
    }

    void rentCar() {
        string name = getInput("\nEnter the name of the car to rent: ");
        int index = findCarIndex(name);

        if (index == -1) {
            cout << "Car not found.\n";
            return;
        }

        if (!inventory[index]->getAvailability()) {
            cout << "This car is already rented.\n";
            return;
        }

        string startDate = getInput("Enter rent start date in YYYY-MM-DD format: ");
        string endDate = getInput("Enter rent return date in YYYY-MM-DD format: ");

        if (!isValidDateFormat(startDate) || !isValidDateFormat(endDate)) {
            cout << "Invalid date format. Use YYYY-MM-DD.\n";
            return;
        }

        inventory[index]->rentCar(startDate, endDate);
        cout << name << " has been rented successfully.\n";
    }

    void returnCar() {
        string name = getInput("\nEnter the name of the car to return: ");
        int index = findCarIndex(name);

        if (index == -1) {
            cout << "Car not found.\n";
            return;
        }

        if (inventory[index]->getAvailability()) {
            cout << "This car is already available.\n";
            return;
        }

        inventory[index]->returnCar();
        cout << name << " has been returned successfully.\n";
    }

    void listCars() const {
        if (inventory.empty()) {
            cout << "\nNo cars are currently registered.\n";
            return;
        }

        cout << "\nCurrent Car Inventory:\n";

        for (const auto& car : inventory) {
            car->displayInfo();
        }
    }

    void sortCars() {
        if (inventory.empty()) {
            cout << "\nNo cars to sort.\n";
            return;
        }

        cout << "\nSort Cars By:\n";
        cout << "1. Name\n";
        cout << "2. Type\n";
        cout << "3. Rent Start Date\n";
        cout << "4. Rent Return Date\n";

        int choice = getMenuChoice("Enter choice: ");

        if (choice == 1) {
            sort(inventory.begin(), inventory.end(),
                [](const unique_ptr<Car>& a, const unique_ptr<Car>& b) {
                    return a->getName() < b->getName();
                });
            cout << "Cars sorted by name.\n";
        } else if (choice == 2) {
            sort(inventory.begin(), inventory.end(),
                [](const unique_ptr<Car>& a, const unique_ptr<Car>& b) {
                    return a->getType() < b->getType();
                });
            cout << "Cars sorted by type.\n";
        } else if (choice == 3) {
            sort(inventory.begin(), inventory.end(),
                [](const unique_ptr<Car>& a, const unique_ptr<Car>& b) {
                    return a->getRentStart() < b->getRentStart();
                });
            cout << "Cars sorted by rent start date.\n";
        } else if (choice == 4) {
            sort(inventory.begin(), inventory.end(),
                [](const unique_ptr<Car>& a, const unique_ptr<Car>& b) {
                    return a->getRentEnd() < b->getRentEnd();
                });
            cout << "Cars sorted by rent return date.\n";
        } else {
            cout << "Sorting choice is invalid.\n";
            return;
        }

        listCars();
    }
};

int main() {
    RentalSystem system;
    int choice;

    do {
        cout << "\nCar Rental System Menu\n";
        cout << "1. Rent a Car\n";
        cout << "2. Return a Car\n";
        cout << "3. Register a New Car\n";
        cout << "4. Deregister a Car\n";
        cout << "5. List Cars\n";
        cout << "6. Sort Cars\n";
        cout << "7. Quit\n";

        choice = getMenuChoice("Enter your choice: ");

        if (choice == 1) {
            system.rentCar();
        } else if (choice == 2) {
            system.returnCar();
        } else if (choice == 3) {
            system.registerCar();
        } else if (choice == 4) {
            system.deregisterCar();
        } else if (choice == 5) {
            system.listCars();
        } else if (choice == 6) {
            system.sortCars();
        } else if (choice == 7) {
            cout << "Exiting Car Rental System. Goodbye!\n";
        } else {
            cout << "Invalid choice. Please enter a number from 1 to 7.\n";
        }

    } while (choice != 7);

    return 0;
}
