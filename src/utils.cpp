#include <fstream>
#include <vector>
#include <iostream>
using namespace std;



bool isStringOnlyAlphabet(string &str) {
    for(int i = 0; i < str.length(); i++) {
        if(!isalpha(str[i])) 
            return false;
    }

    return true;
}

// Validasi Input
bool isUserInputValid(string &input) {
    return ( 
        input.length() == 5 &&
        isStringOnlyAlphabet(input)
    );
}

// to upper a string
string toUpperString(string &word) {
    for(int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
    }
    return word;
}

vector<string> loadWords(const string &filename) {
    vector<string> words;
    ifstream file(filename);
    string word;
    while (file >> word) {
        words.push_back(toUpperString(word));
    }
    return words;
}

void printGreen(char c) {
    cout << "\033[32m" << c << "\033[0m";
}

void printYellow(char c) {
    cout << "\033[33m" << c << "\033[0m";
}

void printGray(char c) {
    cout << "\033[90m" << c << "\033[0m";
}
