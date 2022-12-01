#ifndef __TEXT__
#define __TEXT__

#include <string>

class Text {
    public:
        Text(std::string textInput);
        Text() {}
        std::string raw;
        std::string caps;
        std::string alphabetic;
    private:
        std::string toUpper();
        std::string removeIrregular();
};

#endif