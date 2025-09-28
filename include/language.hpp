#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#include <iostream>
#include <string>
#include <unordered_map>

class LanguageSystem {
    public:
        std::string lang;
        unordered_map<std::string, std::string> sentence;
        unordered_map<std::string, std::string> enSentence;
        unordered_map<std::string, std::string> idSentence;
        void setLang(std::string code);
};
#endif