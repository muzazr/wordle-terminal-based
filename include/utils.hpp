#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
using namespace std;

// load kata dari file
std::vector<std::string> loadWords(const std::string &filename);

bool isStringOnlyAlphabet(std::string &str);
bool isUserInputValid(std::string &input);
std::string toUpperString(std::string &word);

// print warna ke terminal
std::string printGreen(char c);
std::string printYellow(char c);
std::string printGray(char c);

#endif
