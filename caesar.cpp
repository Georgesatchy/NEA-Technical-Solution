#include "caesar.hpp"

Caesar::Caesar(std::string ciphertextInput, int shiftInput) {
    ciphertext = ciphertextInput;
    shift = shiftInput;
}

char Caesar::translate(char character) {
    int ascii = int(character);
    if (65 <= ascii <= 90) {
        ascii = (ascii + shift - 65)%26 + 65;
        return char(ascii);
    } else if (97 <= ascii <= 122) {
        ascii = (ascii + shift - 97)%26 + 97;
        return char(ascii);
    } else {
        return character;
    }
}

std::string Caesar::decrypt() {
    std::string result = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        result += translate(ciphertext[i]);
    }
    return result;
}