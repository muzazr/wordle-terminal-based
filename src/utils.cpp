#include "utils.hpp"
#include <fstream>
#include <iostream>
using namespace std;

vector<string> loadWords(const string &filename) {
    vector<string> words;
    ifstream file(filename);
    string word;
    while (file >> word) {
        words.push_back(word);
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
