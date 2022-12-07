#include "caesar.hpp"


const char * alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char shiftedAlphabet[26];

struct decryption {
    float score;
    std::string text;
};

namespace caesar {
    std::string decrypt(std::string text, int shift) { // Decrypts a message by a given shift by using the translate function on each character
        std::string resultString = "";
        // Create an alphabet for the shift
        for (int i = shift; i < 26; i++) {
            shiftedAlphabet[i-shift] = alphabet[i];
        }
        for (int i = 0; i < shift; i++) {
            shiftedAlphabet[i+26-shift] = alphabet[i];
        }
        // Translate the string with the new shift alphabet
        return substitution::decrypt(text, shiftedAlphabet);
    }   

    std::string bestSolution(std::string text) { // Unfinished function; designed to use cryptanalysis to directly return the best caesar shift result
        decryption decryptions[26] = {};
        std::string decryptText;
        for (int i = 0; i < 26; i++) {
            decryptions[i].text = decrypt(text, i);
            decryptions[i].score = analyse::charFrequency(decryptions[i].text);
        }
        decryption bestDecryption = decryptions[0];
        for (int i = 1; i < 26; i++) {
            if (decryptions[i].score < bestDecryption.score) {
                bestDecryption = decryptions[i];
            }
        }
    }
}