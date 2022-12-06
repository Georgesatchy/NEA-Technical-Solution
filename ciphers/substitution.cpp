#include "substitution.hpp"

char translate(char character, char shift[26]) {
    int ascii = int(character);
    if ((65 <= ascii) && (ascii <= 90)) {
        return shift[ascii - 65]; // Maps to the new character based on the alphabet in the shift array
    } else { // If the character is not alphabetic, it will just return the original character
        return character;
    }
}

namespace substitution {
    std::string decrypt(std::string ciphertext, char shift[26]) {
        std::string resultString = "";
        for (int i = 0; i < ciphertext.length(); i++) {
            resultString += translate(ciphertext[i], shift);
        }
        return resultString;
    }
}