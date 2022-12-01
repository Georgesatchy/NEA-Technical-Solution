#include "caesar.hpp"

char translate(char character, int shift) {
    int ascii = int(character);
    if ((65 <= ascii) && (ascii <= 90)) {
        ascii = (ascii + shift - 65)%26 + 65;
        return char(ascii);
    } else if ((97 <= ascii) && (ascii <= 122)) {
        ascii = (ascii + shift - 97)%26 + 97;
        return char(ascii);
    } else {
        return character;
    }
}

std::string caesar::decrypt(std::string text, int shift) {
    std::string resultString = "";
    for (int i = 0; i < text.length(); i++) {
        resultString += translate(text[i], shift);
    }
    return resultString;
}   