#pragma once

#include "RotorSettings.h"

#include <map>

struct EnigmaSettings
{
    RotorSettings r1;
    RotorSettings r2;
    RotorSettings r3;
    unsigned char reflectorType;
    std::map<unsigned char, unsigned char> plugboard;
};