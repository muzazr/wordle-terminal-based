#include "../include/game.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int ROW = 6;
const int COLUMN = 5;

void clearTerminal() {
    system("cls");
}

void drawBoard(string answerOfPlayer[6][5]) {
    int width_of_one_column = 5;
    int width_of_row = COLUMN*width_of_one_column + COLUMN + 1;
    // cout << '+' << setfill('-') << setw(width_of_row - 1) << '+' << endl;

    for(int i = 0; i < 2*ROW + 1; i++) {
        if(i % 2 == 0) {
            cout << '+' << setfill('-') << setw(width_of_row-1) << '+';
        } else {
            int row_index = (i+1)/2 - 1;
            if(i == 2*COLUMN) {
                continue;
            }
            for(int j = 0; j < width_of_row; j++) {
                if (j == 0 || j == width_of_row - 1) {
                    cout << "|";
                } else if(j % (width_of_one_column+1) == 0) {
                    cout << "|";
                } else if(j == (width_of_one_column + 1)/2) {
                    cout << answerOfPlayer[row_index][0];
                }
                else if((j - (width_of_one_column + 1)/2) % (width_of_one_column + 1) == 0) {
                    int index_of_letter = (j - (width_of_one_column + 1)/2) / (width_of_one_column + 1);
                    cout << answerOfPlayer[row_index][index_of_letter];
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

void playGame(const vector<string> &secretWords) {
    string answerOfPlayer[ROW][COLUMN];
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COLUMN; j++) {
            answerOfPlayer[i][j] = " ";
        }
    }

    string targetWord = secretWords[rand() % secretWords.size()];
    int guess = 6;
    int correctChar = 0;

    while (guess--) {
        clearTerminal();
        drawBoard(answerOfPlayer);
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
                answerOfPlayer[(ROW - 1) - guess][i] = printGreen(guessWord[i]);
                correctChar++;
                charInTargetWord[indexCharacter]--;
            } else if (charInTargetWord[indexCharacter] > 0) {
                answerOfPlayer[(ROW - 1) - guess][i] = printYellow(guessWord[i]);
                charInTargetWord[indexCharacter]--;
            } else {
                answerOfPlayer[(ROW - 1) - guess][i] = printGray(guessWord[i]);
            }
        }

        cout << endl;

        if (correctChar == 5) {
            clearTerminal();
            drawBoard(answerOfPlayer);
            cout << "Selamat tebakan anda benar!" << endl;
            return;
        } else if (guess > 0) {
            clearTerminal();
            drawBoard(answerOfPlayer);
            cout << "Masih salah, coba lagi!" << endl;
        }
        cout << endl;
    }

    cout << "Yah, anda gagal menebak!" << endl;
    cout << "Jawaban yang benar adalah " << targetWord << endl;
}
