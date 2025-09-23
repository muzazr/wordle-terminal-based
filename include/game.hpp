#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

void drawGameHeaderEnglish();
void drawGameHeaderBahasa();

void drawBoard(std::string answerOfPlayer[6][5]);

void playGameEnglish(const std::vector<std::string> &secretWords);
void playGameBahasa(const std::vector<std::string> &secretWords);

#endif
