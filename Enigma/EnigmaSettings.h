#pragma once

#include "RotorSettings.h"

#include <map>

struct EnigmaSettings
{
    RotorSettings leftRotor;
    RotorSettings centerRotor;
    RotorSettings rightRotor;

    // Type B or C
    unsigned char reflectorType;

    // Mappings of characters connected via plugboard
    // Expect pairs to be inserted both ways
    std::map<unsigned char, unsigned char> plugboard;
};