#pragma once

#include <map>

namespace m3
{
    //rotors can be accessed by their roman numeral number 
    const std::map<int, std::string> rotors = { {1, "EKMFLGDQVZNTOWYHXUSPAIBRCJ"},
                                                {2, "AJDKSIRUXBLHWTMCQGZNPYFVOE"},
                                                {3, "BDFHJLCPRTXVZNYEIWGAKMUSQO"},
                                                {4, "ESOVPZJAYQUIRHXLNFTGKDCMWB"},
                                                {5, "VZBRGITYUPSDNHLXAWMJQOFECK"} };

    //These are positions where a rotor turns over the next rotor. 
    //ie rotor III turns over the next rotor when moving from 'V' to 'W'
    //A blank character is included because there is no 0 rotor. The string should be 1-indexed
    const std::string turnover = " QEVJZ";

    const std::map<unsigned char, std::string> reflectorMap = { {'B', "YRUHQSLDPXNGOKMIEBFZCWVJAT"}, 
                                                                {'C', "FVPJIAOYEDRZXWGCTKUQSBNMHL"} };
}


