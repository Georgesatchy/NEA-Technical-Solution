#ifndef __CAESAR__
#define __CAESAR__

#include <string>
#include <iostream>

class Caesar {
    public:
        Caesar(std::string ciphertextInput, int shiftInput);
        std::string ciphertext;
        int shift;
        std::string decrypt();
    private:
        char translate(char character);
};

#endif