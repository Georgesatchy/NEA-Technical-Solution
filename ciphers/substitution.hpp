#ifndef __SUBSTITUTION__
#define __SUBSTITUTION__

#include <string>

namespace substitution {
    std::string decrypt(std::string ciphertext, char shift[26]);
}

#endif