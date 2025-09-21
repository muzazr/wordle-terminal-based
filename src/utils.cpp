#include <fstream>
#include <vector>
#include <iostream>
using namespace std;



bool isStringOnlyAlphabet(string &str) {
    for(int i = 0; i < str.length(); i++) {
        if(!isalpha(str[i])) //use function isalpha() from cctype library
            return false;
    }

    return true;
}

//ensuring input comply with the rules
bool isUserInputValid(string &input) {
    return ( 
        input.length() == 5 &&
        isStringOnlyAlphabet(input)
    );
}

//make a guess uppercase string
string toUpperString(string &word) {
    for(int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]); //toupper() function from cctype library
    }
    return word;
}

//import dictionary
vector<string> loadWords(const string &filename) {
    vector<string> words;
    ifstream file(filename);
    string word;
    while (file >> word) {
        words.push_back(toUpperString(word));
    }
    return words;
}

//change color output
string printGreen(char c) {
    string letter = {c, '\0'};
    string result = "\033[32m" + letter + "\033[0m";
    return result;
}
string printGreen(string str) {
    return "\033[32m" + str + "\033[0m";
}

//change color output
string printYellow(char c) {
    string letter = {c, '\0'};
    string result = "\033[33m" + letter + "\033[0m";
    return result;
}
string printYellow(string str) {
    return "\033[33m" + str + "\033[0m";
}

//change color output
string printGray(char c) {
    string letter = {c, '\0'};
    string result = "\033[90m" + letter + "\033[0m";
    return result;
}
string printGray(string str) {
    return "\033[90m" + str + "\033[0m";
}
