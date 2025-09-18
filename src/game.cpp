#include "../include/game.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

void playGame(const vector<string> &secretWords) {
    string targetWord = secretWords[rand() % secretWords.size()];
    int guess = 6;
    int correctChar = 0;

    while (guess--) {
        string guessWord;
         do {
                cout << "Silahkan masukkan tebakan anda: ";
                cin >> guessWord;
                bool isInputValid = isUserInputValid(guessWord);
                if(!isInputValid) 
                    cout << "Pastikan kata berjumlah lima dan input hanya mengandung alfabet" << endl;
                else 
                    break;
            } while(true);
        guessWord = toUpperString(guessWord);
        correctChar = 0;

        // hitung jumlah masing-masing huruf
        int charInTargetWord[26] = {};
        for (int i = 0; i < targetWord.length(); i++) {
            int indexCharacter = targetWord[i] - 'A' + 1;
            charInTargetWord[indexCharacter]++;
        }

        // cek hasil tebakan
        for (int i = 0; i < guessWord.length(); i++) {
            int indexCharacter = guessWord[i] - 'A' + 1;
            if (guessWord[i] == targetWord[i]) {
                printGreen(guessWord[i]);
                correctChar++;
                charInTargetWord[indexCharacter]--;
            } else if (charInTargetWord[indexCharacter] > 0) {
                printYellow(guessWord[i]);
                charInTargetWord[indexCharacter]--;
            } else {
                printGray(guessWord[i]);
            }
        }

        cout << endl;

        if (correctChar == 5) {
            cout << "Selamat tebakan anda benar!" << endl;
            return;
        } else if (guess > 0) {
            cout << "Masih salah, coba lagi!" << endl;
        }
        cout << endl;
    }

    cout << "Yah, anda gagal menebak!" << endl;
    cout << "Jawaban yang benar adalah " << targetWord << endl;
}
