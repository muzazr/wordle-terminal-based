#include <iostream>
#include <vector>
#include <string>
#include "game.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    srand(time(0));

    vector<string> secretWords = loadWords("words.txt");
    bool play = true;

    while (play) {
        playGame(secretWords);  // dipindahkan ke game.cpp
        cout << "Mau bermain lagi? (y/n) : ";
        char playAgain;
        cin >> playAgain;
        play = (playAgain == 'y');
    }
}