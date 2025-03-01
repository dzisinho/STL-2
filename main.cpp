#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

string normalizeWord(const string& word) {
    string result;
    for (char ch : word) {
        if (isalpha(ch)) result += tolower(ch);
    }
    return result;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    map<string, int> wordCount;
    string word;

    while (inputFile >> word) {
        word = normalizeWord(word);
        if (!word.empty()) wordCount[word]++;
    }
    inputFile.close();

    string mostFrequentWord;
    int maxCount = 0;
    cout << "Word frequency dictionary:" << endl;
    for (const auto& entry : wordCount) {
        const string& w = entry.first;
        int count = entry.second;
        cout << w << ": " << count << endl;
        outputFile << w << ": " << count << endl;
        if (count > maxCount) {
            mostFrequentWord = w;
            maxCount = count;
        }
    }

    cout << "\nMost frequent word: " << mostFrequentWord << " (" << maxCount << " times)" << endl;
    outputFile << "\nMost frequent word: " << mostFrequentWord << " (" << maxCount << " times)" << endl;
    outputFile.close();
    return 0;
}