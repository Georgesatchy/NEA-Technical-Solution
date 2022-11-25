#include "caesar.hpp"

Caesar::Caesar(std::string ciphertextInput, int shiftInput) {
    for (char& c: ciphertextInput) {
        c = toupper(c);
    }
    ciphertext = ciphertextInput;
    shift = shiftInput;
}

char Caesar::translate(char character) {
    int ascii = int(character);
    if ((65 <= ascii) && (ascii <= 90)) {
        ascii = (ascii + shift - 65)%26 + 65;
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