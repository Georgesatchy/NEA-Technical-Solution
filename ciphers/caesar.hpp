#ifndef __CAESAR__
#define __CAESAR__

#include <string>

#include "../text.hpp"

/* 
Define a "caesar" namespace so the Caesar-based function can be called in the main cipherTools 
file using caesar::FUNCTION() to avoid function name clashes with other cipher-types.
*/

namespace caesar { 
    // This allows the functions to be imported into the main cipherTools.cpp file
    std::string decrypt(std::string ciphertext, int shiftInput);
    std::string bestSolution(std::string ciphertext);
}

#endif