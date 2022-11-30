#include "text.hpp"

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