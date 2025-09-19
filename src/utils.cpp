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

string printGreen(char c) {
    string letter = {c, '\0'};
    string result = "\033[32m" + letter + "\033[0m";
    return result;
}

string printYellow(char c) {
    string letter = {c, '\0'};
    string result = "\033[33m" + letter + "\033[0m";
    return result;
}

string printGray(char c) {
    string letter = {c, '\0'};
    string result = "\033[90m" + letter + "\033[0m";
    return result;
}
