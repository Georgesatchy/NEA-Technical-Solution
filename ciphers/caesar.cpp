#include "caesar.hpp"
#include "../analyse.hpp"

// This function shifts an inputted character by an inputted shift amount by convering it to an ASCII code
char translate(char character, int shift) {
    int ascii = int(character);
    if ((65 <= ascii) && (ascii <= 90)) {
        ascii = (ascii + shift - 65)%26 + 65;
        return char(ascii);
    } else if ((97 <= ascii) && (ascii <= 122)) {
        ascii = (ascii + shift - 97)%26 + 97;
        return char(ascii);
    } else { // If the character is not alphabetic, it will just return the original character
        return character;
    }
}

namespace caesar {
    std::string decrypt(std::string text, int shift) { // Decrypts a message by a given shift by using the translate function on each character
        std::string resultString = "";
        for (int i = 0; i < text.length(); i++) {
            resultString += translate(text[i], shift);
        }
        return resultString;
    }   

    std::string bestSolution(std::string text) { // Unfinished function; designed to use cryptanalysis to directly return the best caesar shift result
        int scores[26] = {};
        for (int i = 0; i < 26; i++) {
            scores[i] = analyse::charFrequency(decrypt(text, i));
        }
        for (int i = 0; i < 26; i++) {
        }
    }
}