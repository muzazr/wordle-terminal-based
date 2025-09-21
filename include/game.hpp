#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

void drawGameHeader();

void drawBoard(std::string answerOfPlayer[6][5]);

void playGame(const std::vector<std::string> &secretWords);

#endif
