#pragma once

const int NUM_CHARS_IN_ALPHABET = 26;

#include <string>

#include "RotorSettings.h"

class Rotor
{
private:
    std::string mapping;
    std::string inverseMapping;
    unsigned char position;
    unsigned int ringSetting;
    void GenerateInverse();
public:
    Rotor(const RotorSettings& settings);
    unsigned char Translate(unsigned char inputChar) const;
    unsigned char InverseTranslate(unsigned char inputChar) const;
    //returns true if the next rotor should also increment
    bool Increment();
};