#include "caesar.hpp"

Caesar::Caesar(Text ciphertext, int shiftInput) {
    text = ciphertext;
    shift = shiftInput;
}

char Caesar::translate(char character) {
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

Text Caesar::decrypt() {
    std::string resultString = "";
    for (int i = 0; i < text.raw.length(); i++) {
        resultString += translate(text.raw[i]);
    }
    return Text(resultString);
}