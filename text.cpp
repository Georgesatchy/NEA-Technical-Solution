#include "text.hpp"

/*
This text class allows a string to be formatted such that it can easily be decrypted and displayed

This includes storing the raw inputting string, removing non alphabetic 
characters and converting it to upper case text.
*/

std::string format(std::string raw) {
    std::string result;
    result = Text::removeIrregular(raw);
    result = Text::toUpper(result);
    return result;
}

namespace Text {
    std::string removeIrregular(std::string raw) {
        std::string alph = "";
        for (char& c: raw) {
            int ascii = int(c);
            if ((65 <= ascii) && (ascii <= 90)) {
                alph += c;
            } else if ((97 <= ascii) && (ascii <= 122)) {
                alph += c;
            }
        }
        return alph;
    }

    std::string toUpper(std::string alphabetic) {
        std::string upper = "";
        for (char& c: alphabetic) {
            upper += toupper(c);
        }
        return upper;
    }
}