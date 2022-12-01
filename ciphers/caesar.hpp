#ifndef __CAESAR__
#define __CAESAR__

#include <string>

#include "../text.hpp"

namespace caesar {
    std::string decrypt(std::string ciphertext, int shiftInput);
}

#endif