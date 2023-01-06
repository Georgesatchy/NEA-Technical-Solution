#ifndef __TEXT__
#define __TEXT__

#include <string>

namespace Text {
    std::string removeIrregular(std::string raw);
    std::string toUpper(std::string result);
}

std::string format(std::string raw);

struct decryption {
    float score;
    std::string text;
};

#endif