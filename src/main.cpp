#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;


vector <string> loadWords (const string &filename){
    vector <string> temp_words;
    ifstream file(filename);
    string word;

    while(file >> word) {
        temp_words.push_back(word);
    }

    file.close();
    return temp_words; //mengembalikan temp_words yang berisi kata dari dictionary
}

bool isStringOnlyAlphabet(string &str) {
    for(int i = 0; i < str.length(); i++) {
        if(!isalpha(str[i])) 
            return false;
    }

    return true;
}

// Validasi Input
bool isUserInputValid(string &input) {
    return ( 
        input.length() == 5 &&
        isStringOnlyAlphabet(input)
    );
}

// to upper a string
string toUpperString(string &word) {
    for(int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
    }
    return word;
}

int main () {

    srand(time(0)); //untuk seed function rand

    vector <string> secretWords = loadWords("words.txt"); //words.txt adalah dictionary
    bool play = true; //true = lanjut bermain, false = berhenti bermain

    while (play) {
        string targetWord = secretWords[rand() % secretWords.size()]; //randomize kata yang harus ditebak
        targetWord = toUpperString(targetWord);
        int guess = 6; //kesempatan player untuk menebak
        int correctChar = 0; //jumlah character yang berhasil ditebak pada setiap kesempatan

        while (guess--) {
            string guessWord;
            do {
                cout << "Silahkan masukkan tebakan anda: ";
                cin >> guessWord;
                if(!isUserInputValid(guessWord)) 
                    cout << "Pastikan kata berjumlah lima dan input hanya mengandung alfabet" << endl;
                else 
                    break;
            } while(true);
            guessWord = toUpperString(guessWord);
            
            correctChar = 0;

            //Section ini untuk menghitung jumlah masing-masing character pada kata yang harus ditebak
            //Contoh: JOGJA -> J(2), O(1), G(1), A(1)
            int charInTargetWord[26] = {};
            for(int i = 0; i < targetWord.length(); i++) {
                int indexCharacter = targetWord[i] - 'A' + 1;
                charInTargetWord[indexCharacter]++;
            }

            //Section untuk mengecek ketepatan tebakan
            for(int i = 0; i < guessWord.length(); i++) {
                int indexCharacter = guessWord[i] - 'A' + 1;
                if(guessWord[i] == targetWord[i]) { //huruf benar, posisi benar
                    cout << "\033[32m" << guessWord[i] << "\033[0m";
                    correctChar++; //hanya bertambah ketika huruf & benar posisi benar
                    charInTargetWord[indexCharacter]--;
                } else if (charInTargetWord[indexCharacter] > 0) { //huruf benar, posisi salah
                    cout << "\033[33m" << guessWord[i] << "\033[0m";
                    charInTargetWord[indexCharacter]--;
                } else { //huruf salah, posisi salah
                    cout << "\033[90m" << guessWord[i] << "\033[0m";
                }
            }

            cout << endl;
            
            if(correctChar == 5) { //berhasil menebak 5 huruf dengan posisi benar dan huruf benar
                cout << "Selamat tebakan anda benar!" << endl;
                break;
            } else if (guess > 0 && correctChar != 5){
                cout << "Masih salah, coba lagi!" << endl;
            }
            cout << endl;
        }

        if(guess == 0 && correctChar != 5) {
            cout << "Yah, anda gagal menebak!" << endl;
        }

        cout << "Jawaban yang benar adalah " << targetWord << endl;

        cout << "Mau bermain lagi? (y/n) : ";
        char playAgain;
        cin >> playAgain;
        if(playAgain == 'y') {
            play = true; //bermain lagi
        } else {
            play = false; //berhenti bermain, program selesai
        }
    }

}