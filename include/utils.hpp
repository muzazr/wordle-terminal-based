#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
using namespace std;

// load word from dictionary
std::vector<std::string> loadWords(const std::string &filename);

//checking user input
bool isStringOnlyAlphabet(std::string &str);
bool isUserInputValid(std::string &input);
std::string toUpperString(std::string &word);

// print color to terminal
std::string printGreen(char c);
std::string printGreen(string str);

std::string printYellow(char c);
std::string printYellow(string str);

std::string printGray(char c);
std::string printGray(string str);


#endif
