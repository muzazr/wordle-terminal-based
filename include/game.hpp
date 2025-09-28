#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include "../include/language.hpp"


void drawGameHeaderEnglish();
void drawGameHeaderBahasa();

void drawBoard(std::string answerOfPlayer[6][5]);

void playGame(const std::vector<std::string> &secretWords, LanguageSystem &languageSystem);

#endif
