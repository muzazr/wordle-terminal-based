
#include <iostream>
#include <unordered_map>
using namespace std;

/*
Language code
en - english
id - indonesia
*/

class LanguageSystem {
    public:
        string lang = "en";
        unordered_map<string, string> sentence; 
        unordered_map<string, string> enSentence = {
            {"play_again", "Play again?"},
            {"please_give_your_answer", "Please give your answer"},
            {"explain_valid_input_characteristic", "Ensure that the word has five letters, the input only contains letters, and the word is valid."},
            {"congratulation", "Congratulations, your guess is correct!"},
            {"you_have_successfully_guessed", "You have successfully guessed"},
            {"times", "times"},
            {"still_incorrect", "Still incorrect, try again!"},
            {"you_failed_1", "Well, you failed to guess correctly :("},
            {"you_failed_2", "The correct answer is"},
            {"you_have_failed_guessed", "You have failed guessed"}
        };
        unordered_map<string, string> idSentence = {
            {"play_again", "Ingin bermain lagi?"},
            {"please_give_your_answer", "Masukkan jawaban anda"},
            {"explain_valid_input_characteristic", "Pastikan jawaban anda hanya 5 karakter, hanya berupa huruf, dan kata valid."},
            {"congratulation", "Selamat, tebakan anda benar!"},
            {"you_have_successfully_guessed", "Kamu telah berhasil menebak sebanyak"},
            {"times", "kali"},
            {"still_incorrect", "Jawaban anda masih salah, coba lagi!"},
            {"you_failed_1", "Yahh, anda gagal untuk menebak dengan benar :("},
            {"you_failed_2", "Jawaban yang benar adalah"},
            {"you_have_failed_guessed", "Kamu telah gagal menebak sebanyak"}
        };

        void setLang(string code) {
            lang = code;
            if(lang == "en") {
                sentence = enSentence;
            } else if (lang == "id") {
                sentence = idSentence;
            }
        }
};
