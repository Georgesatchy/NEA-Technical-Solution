#ifndef __ANALYSE__
#define __ANALYSE__

#include <string>
#include <iostream>

#include "text.hpp"

class Analyse {
    public:
        Analyse(Text textInput);
        float charFrequency();
    private:
        Text text;
};

#endif