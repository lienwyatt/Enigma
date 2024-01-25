#pragma once

const int NUM_IN_ALPHABET = 26;

#include <string>


class Rotor
{
private:
    std::string mapping;
    unsigned char position;
public:
    Rotor(const std::string& letters, int startingPosition);
    unsigned char translate(unsigned char inputChar) const;
    //returns true if the next rotor should also increment
    bool increment();
};