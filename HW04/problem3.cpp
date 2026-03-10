#include <iostream>
#include <string>
using namespace std;

class Animal {
	private:
		string species;
		
	public:
		void setSpecies(string s) {
			species = s;
		}
		
		string getSpecies() {
			return species;
		}
};

class Dog: public Animal {
	private:
		string breed;

	public:
		void setBreed(string b) {
			breed = b;
		}
		
		string getBreed() {
			return breed;
		}
};

int main() {
	Dog myDog;
	myDog.setSpecies("Mammal");
	myDog.setBreed("Labrador");

	cout << "Species: " << myDog.getSpecies() << endl;
	cout << "Breed: " << myDog.getBreed() << endl;

	return 0;
}
	
		
