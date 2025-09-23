#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include "../include/game.hpp"
#include "../include/utils.hpp"

using namespace std;

int main() {
    srand(time(0));

    cout << setfill('=') << setw(31) << '=' << endl;
    cout << "   << WORDLE (C++ Edition) >>   " << endl; 
    cout << setfill('=') << setw(31) << '=' << endl;
    cout << "   Guess the 5-letter word!   " << endl << endl;

    while(true) {
        cout << "Choose language:\n(1) English\n(2) Bahasa Indonesia\nSelect\t\t\t: ";
        char language; cin >> language;
        
        if(language == '1') {
            vector<string> secretWords = loadWords("../src/wordsEnglish.txt");
            bool play = true; //to give players the option to play again, true for play again
            
            while (play) {
                playGameEnglish(secretWords);
                cout << "Play again? (y/n) : ";
                char playAgain;
                cin >> playAgain;
                play = (playAgain == 'y');
            }
            break;
        } else if (language == '2') {
            vector<string> secretWords = loadWords("../src/wordsBahasa.txt");
            bool play = true; //to give players the option to play again, true for play again
            
            while (play) {
                playGameBahasa(secretWords);
                cout << "Ingin bermain lagi? (y/n) : ";
                char playAgain;
                cin >> playAgain;
                play = (playAgain == 'y');
            }
            break;
        }
    }
}
