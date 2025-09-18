#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

// load kata dari file
std::vector<std::string> loadWords(const std::string &filename);

// print warna ke terminal
void printGreen(char c);
void printYellow(char c);
void printGray(char c);

#endif
