#include "../include/game.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int ROW = 6; //board size
const int COLUMN = 5; //board size
int scorePlayer = 0; //add if the player guessess correctly

//reset terminal after player give input
void clearTerminal() {
    system("cls");
}

void drawGameHeader() {
    cout << setfill('=') << setw(31) << '=' << endl;
    cout << "   << WORDLE (C++ Edition) >>   " << endl; 
    cout << setfill('=') << setw(31) << '=' << endl;
    cout << "   Guess the 5-letter word!   " << endl << endl;
    cout << printGreen("Green") << " : correct " << endl;
    cout << printYellow("Yellow") << ": correct, but in the " << endl << "        wrong position" << endl;
    cout << printGray("Gray") << "  : incorrect" << endl << endl;

}

//visualization of wordle board
void drawBoard(string answerOfPlayer[6][5]) {

    int width_of_one_column = 5; //size of column every char
    int width_of_row = COLUMN*width_of_one_column + COLUMN + 1; //give a column boundaries

    // Render the Wordle board by iterating through rows and columns.
    // Even indices (i % 2 == 0) draw horizontal separators,
    // odd indices draw the row content with vertical dividers and letters.
    for(int i = 0; i < 2*ROW + 1; i++) {

        if(i % 2 == 0) {
            // Horizontal border line
            cout << '+' << setfill('-') << setw(width_of_row-1) << '+';
        } else {
            int row_index = (i+1)/2 - 1;
            if(i == 2*COLUMN) {
                continue;
            }

            // Draw the content of each cell in the current row
            for(int j = 0; j < width_of_row; j++) {
                if (j == 0 || j == width_of_row - 1) {
                    cout << "|"; //left or right border
                } else if(j % (width_of_one_column+1) == 0) {
                    cout << "|"; //vertical cell divider
                } else if(j == (width_of_one_column + 1)/2) {
                    cout << answerOfPlayer[row_index][0]; //first letter
                }
                else if((j - (width_of_one_column + 1)/2) % (width_of_one_column + 1) == 0) {
                    int index_of_letter = (j - (width_of_one_column + 1)/2) / (width_of_one_column + 1);
                    cout << answerOfPlayer[row_index][index_of_letter]; //subsequent letter
                } else {
                    cout << " "; //padding inside the cell
                }
            }
        }
        cout << endl;
    }
}

// Redraw a terminal: clear screen, draw game header, and draw wordle board
void drawTerminal(
    string answerOfPlayer[6][5]
) {
    clearTerminal();
    drawGameHeader();
    drawBoard(answerOfPlayer);
}

//logic wordle
void playGame(const vector<string> &secretWords) {
    string answerOfPlayer[ROW][COLUMN];
    
    for(int i = 0; i < ROW; i++) { //setup wordle board
        for(int j = 0; j < COLUMN; j++) {
            answerOfPlayer[i][j] = " ";
        }
    }

    string targetWord = secretWords[rand() % secretWords.size()]; //give random word to guess
    int guess = 6;
    int correctChar = 0; //variable that count right char and right position for every guess

    while (guess--) {
        drawTerminal(answerOfPlayer);
        string guessWord;
         do { //ensuring guesses comply with the rules
                cout << "Please give your answer\t: ";
                cin >> guessWord;
                bool isInputValid = isUserInputValid(guessWord);
                if(!isInputValid) 
                    cout << "Ensure that the word has five letters and that the input only contains letters." << endl;
                else 
                    break;
            } while(true);
        guessWord = toUpperString(guessWord); //convert to uppercase if player give lowercase input
        correctChar = 0;
        
        //count every character player guess
        //example: JOGJA -> J(2), O(1), G(1), A(1)
        int charInTargetWord[26] = {};
        int charInGuessWord[26] = {};
        for (int i = 0; i < targetWord.length(); i++) {
            int indexCharacter = targetWord[i] - 'A';
            charInTargetWord[indexCharacter]++;
        }
        for (int i = 0; i < guessWord.length(); i++) {
            int indexCharacter = guessWord[i] - 'A';
            charInGuessWord[indexCharacter]++;
        }

        // for(int i = 0; i < 26; i++) {
        //     cout << charInTargetWord[i] << " ";
        // }
        // cout << endl;

        //check player guess
        for (int i = 0; i < guessWord.length(); i++) {
            int indexCharacter = guessWord[i] - 'A';
            if (guessWord[i] == targetWord[i]) { //correct char and position
                answerOfPlayer[(ROW - 1) - guess][i] = printGreen(guessWord[i]);
                correctChar++;
                charInTargetWord[indexCharacter]--;
                charInGuessWord[indexCharacter]--;
            } else if (
                charInTargetWord[indexCharacter] > 0 
                && charInTargetWord[indexCharacter] >= charInGuessWord[indexCharacter]
                ) { //correct char and wrong position
                answerOfPlayer[(ROW - 1) - guess][i] = printYellow(guessWord[i]);
                charInTargetWord[indexCharacter]--;
                charInGuessWord[indexCharacter]--;
            } else { //wrong char and position
                answerOfPlayer[(ROW - 1) - guess][i] = printGray(guessWord[i]);
            }
        }

        if (correctChar == 5) { 
            //there is 5 char correct char and position, 
            //it means guess play   er same with target word
            drawTerminal(answerOfPlayer);
            scorePlayer++;
            cout << "\nCongratulations, your guess is correct!" << endl;
            cout << "You have successfully guessed " << scorePlayer << " times." << endl << endl;
            return;
        } else if (guess > 0) {
            drawTerminal(answerOfPlayer);
            cout << "Still incorrect, try again!" << endl;
        }
        cout << endl;
    }

    cout << "Well, you failed to guess correctly :(" << endl;
    cout << "The correct answer is " << targetWord << endl;
    cout << "You have successfully guessed " << scorePlayer << " times." << endl << endl;
}
