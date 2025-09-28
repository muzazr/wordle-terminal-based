#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include "../include/language.hpp"
#include "../include/game.hpp"
#include "../include/utils.hpp"

using namespace std;
LanguageSystem languageSystem;
int main() {
    srand(time(0));

    cout << setfill('=') << setw(31) << '=' << endl;
    cout << "   << WORDLE (C++ Edition) >>   " << endl; 
    cout << setfill('=') << setw(31) << '=' << endl;
    cout << "   Guess the 5-letter word!   " << endl << endl;
    

    while(true) {
        cout << "Choose language:\n(1) English\n(2) Bahasa Indonesia\nSelect\t\t\t: ";
        char language; cin >> language;
        vector<string> secretWords;
        if(language == '1') {
            languageSystem.setLang("en");
            secretWords = loadWords("../src/wordsEnglish.txt");
        } else if(language == '2') {
            languageSystem.setLang("id");
            secretWords = loadWords("../src/wordsBahasa.txt");
        }
        
        bool play = true;
        while(play) {
            playGame(secretWords, languageSystem);
            cout << languageSystem.stringResource("play_again") << " (y/n) : ";
            char playAgain;
            cin >> playAgain;
            play = (playAgain == 'y');
        }
        break;
        
    }
}
