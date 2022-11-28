#include "text.hpp"

Text::Text(std::string textInput) {
    std::cout << 1 << std::endl;
    raw = textInput;
    std::cout << 2 << std::endl;
    caps = toUpper();
    std::cout << 3 << std::endl;
    alphabetic = removeIrregular();
    std::cout << 4 << std::endl;
}

std::string Text::toUpper() {
    std::cout << "2a" << std::endl;
    char* upper = "";
    std::cout << "2b" << std::endl;
    for (char& c: raw) {
        upper += toupper(c);
    }
    std::cout << "2c" << std::endl;
    return upper;
}

std::string Text::removeIrregular() {
    char* alph = "";
    for (char& c: caps) {
        int ascii = int(c);
        if ((65 <= ascii) && (ascii <= 90)) {
            alph += c;
        }
    }
    std::string str(alph);
    return alph;
}