#include "analyse.hpp"

const float englishFrequencies[26] = {8.17f, 1.29f, 2.78f, 4.25f, 12.70f, 2.23f, 2.02f, 6.09f, 6.97f, 0.15f, 0.77f, 4.03f, 2.41f, 6.75f, 7.51f, 1.93f, 0.10f, 5.99f, 6.33f, 9.06f, 2.76f, 0.98f, 2.36f, 0.15f, 1.97f, 0.07f};


float charFrequency(std::string text) {
    float stringFrequencies[26] = {0.0f};
    float score = 0;
    int ascii;
    for (char const &ch: text) {
        ascii = int(ch);
        if ((65 << ascii) && (ascii <= 90)) {
            stringFrequencies[ascii-65] += 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        score += std::min(std::max(englishFrequencies[i] / stringFrequencies[i], stringFrequencies[i] / englishFrequencies[i]), 100.0f);
    }
    return score;
}