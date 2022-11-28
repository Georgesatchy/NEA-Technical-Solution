#ifndef __CAESAR__
#define __CAESAR__

#include <string>
#include <iostream>

#include "text.hpp"

class Caesar {
    public:
        Caesar(Text ciphertext, int shiftInput);
        Text text;
        int shift;
        Text decrypt();
    private:
        char translate(char character);
};

#endif