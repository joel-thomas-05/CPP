#include <iostream>
#include <string>
using namespace std;

class Book {

	private:
		string title;
		int pages;

	public:
		void setTitle(string t) {
			title = t;
		}
		
		void setPages(int p) {
			pages = p;
		}

		string getTitle() {
			return title;
		}
		
		int getPages() {
			return pages;
		}

};

int main() {
	Book myBook;
	myBook.setTitle("The Alchemist");
	myBook.setPages(208);

	cout << "Title: " << myBook.getTitle() << endl;
	cout << "Number of Pages: " << myBook.getPages() << endl;

	return 0;
}
