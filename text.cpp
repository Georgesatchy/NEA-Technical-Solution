#include "text.hpp"

/*
This text class allows a string to be formatted such that it can easily be decrypted and displayed

This includes storing the raw inputting string, removing non alphabetic 
characters and converting it to upper case text.
*/

Text::Text(std::string textInput) {
    raw = textInput;
    alphabetic = removeIrregular();
    caps = toUpper();
}

std::string Text::removeIrregular() {
    std::string alph = "";
    for (char& c: raw) {
        int ascii = int(c);
        if ((65 <= ascii) && (ascii <= 90)) {
            alph += c;
        } else if ((97 <= ascii) && (122 <= ascii)) {
            alph += c;
        }
    }
    return alph;
}

std::string Text::toUpper() {
    std::string upper = "";
    for (char& c: alphabetic) {
        upper += toupper(c);
    }
    return upper;
}