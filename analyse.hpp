#ifndef __ANALYSE__
#define __ANALYSE__

#include <string>
#include <iostream>

class Analyse {
    public:
        Analyse(std::string textInput);
        float charFrequency();
    private:
        std::string text;
};

#endif