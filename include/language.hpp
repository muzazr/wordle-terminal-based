#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#include <iostream>
#include <string>
#include <unordered_map>

class LanguageSystem {
    private:
        std::string lang;
        std::unordered_map<std::string, std::string> sentence;
        std::unordered_map<std::string, std::string> enSentence;
        std::unordered_map<std::string, std::string> idSentence;
    public:
        LanguageSystem();
        void setLang(std::string code);
        std::string stringResource(std::string keyword);
};
#endif