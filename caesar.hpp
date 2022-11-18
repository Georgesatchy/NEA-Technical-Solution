#ifndef __CAESAR__
#define __CAESAR__

#include <string>
#include <iostream>

class Caesar {
    private:
        char translate(char character);
    public:
        Caesar(std::string ciphertextInput, int shiftInput);
        std::string ciphertext;
        int shift;
        std::string decrypt();
};

#endif