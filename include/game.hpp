#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

const int ROW;
const int COLUMN;

void board(std::string answerOfPlayer[6][5]);

void playGame(const std::vector<std::string> &secretWords);

#endif
