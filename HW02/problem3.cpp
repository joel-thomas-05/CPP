#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cout << "Enter a word: " << endl;
    cin >> word;

    char mostFrequent;
    int maxCount = 0;

    for (int i = 0; i < word.length(); i++) {
        int count = 0;

        for (int j = 0; j < word.length(); j++) {
            if (word[i] == word[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            mostFrequent = word[i];
        }
    }

    cout << "Most frequent character: '" << mostFrequent << "'" << endl;

    return 0;
}
