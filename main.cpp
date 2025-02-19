#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

class Dictionary {
private:
    map<string, string> words;

public:
    void addWord(const string& word, const string& meaning) {
        words[word] = meaning;
    }

    void removeWord(const string& word) {
        words.erase(word);
    }

    void editWord(const string& word, const string& newMeaning) {
        if (words.find(word) != words.end()) {
            words[word] = newMeaning;
        }
        else {
            cout << "Word not found!" << endl;
        }
    }

    void searchWord(const string& word) {
        auto it = words.find(word);
        if (it != words.end()) {
            cout << "Meaning of '" << word << "': " << it->second << endl;
        }
        else {
            cout << "Word not found!" << endl;
        }
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        for (const auto& entry : words) {
            file << entry.first << "," << entry.second << endl;
        }
        file.close();
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        string word, meaning;
        words.clear();
        while (getline(file, word, ',') && getline(file, meaning)) {
            words[word] = meaning;
        }
        file.close();
    }

    void display() {
        for (const auto& entry : words) {
            cout << entry.first << " - " << entry.second << endl;
        }
    }
};

int main() {
    Dictionary dict;
    dict.loadFromFile("dictionary.txt");

    int choice;
    string word, meaning;

    do {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add Word\n2. Remove Word\n3. Edit Word\n4. Search Word\n5. Display Words\n6. Save & Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            dict.addWord(word, meaning);
            break;
        case 2:
            cout << "Enter word to remove: ";
            getline(cin, word);
            dict.removeWord(word);
            break;
        case 3:
            cout << "Enter word to edit: ";
            getline(cin, word);
            cout << "Enter new meaning: ";
            getline(cin, meaning);
            dict.editWord(word, meaning);
            break;
        case 4:
            cout << "Enter word to search: ";
            getline(cin, word);
            dict.searchWord(word);
            break;
        case 5:
            dict.display();
            break;
        case 6:
            dict.saveToFile("dictionary.txt");
            cout << "Dictionary saved. Exiting...\n";
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}