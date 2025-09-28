
#include <iostream>
#include <unordered_map>
#include "..\include\language.hpp"
using namespace std;

/*
Language code
en - english
id - indonesia
*/

LanguageSystem::LanguageSystem() {
    this->lang = "en";
    this->sentence; 
    this->enSentence = {
        {"play_again", "Play again?"},
        {"please_give_your_answer", "Please give your answer"},
        {"explain_valid_input_characteristic", "Ensure that the word has five letters, the input only contains letters, and the word is valid."},
        {"congratulation", "Congratulations, your guess is correct!"},
        {"you_have_successfully_guessed", "You have successfully guessed"},
        {"times", "times"},
        {"still_incorrect", "Still incorrect, try again!"},
        {"you_failed_1", "Well, you failed to guess correctly :("},
        {"you_failed_2", "The correct answer is"},
        {"you_have_failed_guessed", "You have failed guessed"},
        {"game_header_1", "Guess the 5-letter word!"},
        {"game_header_green_explanation", "The letter is in the word and in the correct position"},
        {"game_header_yellow_explanation", "The letter is in the word but in the wrong position"},
        {"game_header_gray_explanation", "The letter is not in the word at all"},
    };
    this->idSentence = {
        {"play_again", "Ingin bermain lagi?"},
        {"please_give_your_answer", "Masukkan jawaban anda"},
        {"explain_valid_input_characteristic", "Pastikan jawaban anda hanya 5 karakter, hanya berupa huruf, dan kata valid."},
        {"congratulation", "Selamat, tebakan anda benar!"},
        {"you_have_successfully_guessed", "Kamu telah berhasil menebak sebanyak"},
        {"times", "kali"},
        {"still_incorrect", "Jawaban anda masih salah, coba lagi!"},
        {"you_failed_1", "Yahh, anda gagal untuk menebak dengan benar :("},
        {"you_failed_2", "Jawaban yang benar adalah"},
        {"you_have_failed_guessed", "Kamu telah gagal menebak sebanyak"},
        {"game_header_1", "Tebak kata dengan panjang 5 karakter!"},
        {"game_header_green_explanation", "Huruf tersebut terdapat dalam kata dan berada pada posisi yang benar."},
        {"game_header_yellow_explanation", "Huruf tersebut ada dalam kata, tetapi berada di posisi yang salah."},
        {"game_header_gray_explanation", "Huruf sama sekali tidak ada dalam kata tersebut."},
    };

};

string LanguageSystem::getLang() {
    return this->lang;
}

void LanguageSystem::setLang(string code) {
    this->lang = code;
    if(lang == "en") {
        this->sentence = enSentence;
    } else if (lang == "id") {
        this->sentence = idSentence;
    }
}
string LanguageSystem::stringResource(string keyword) {
    string sentence;
    try{
        sentence = this->sentence[keyword];
    }
    catch(int error_code){
        sentence = "";
        cout << error_code << endl;
    }
    return sentence;
}
