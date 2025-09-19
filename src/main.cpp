#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "../include/game.hpp"
#include "../include/utils.hpp"

using namespace std;

int main() {
    srand(time(0));

    vector<string> secretWords = loadWords("../src/words.txt");
    bool play = true; //to give players the option to play again, true for play again

    while (play) {
        playGame(secretWords);
        cout << "Want to play again? (y/n) : ";
        char playAgain;
        cin >> playAgain;
        play = (playAgain == 'y');
    }
}