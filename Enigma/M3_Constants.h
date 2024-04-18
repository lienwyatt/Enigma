#pragma once

#include <map>


// Constants that pertain to the M3 iteration of Enigma first used in 1934
namespace m3
{
    // Keys are roman numeral value of each rotor
    // Values are the strings showing output characters that each input character maps to. 
    // So 'A' in Rotor IV maps to 'E'
    const std::map<int, std::string> rotors = { {1, "EKMFLGDQVZNTOWYHXUSPAIBRCJ"},
                                                {2, "AJDKSIRUXBLHWTMCQGZNPYFVOE"},
                                                {3, "BDFHJLCPRTXVZNYEIWGAKMUSQO"},
                                                {4, "ESOVPZJAYQUIRHXLNFTGKDCMWB"},
                                                {5, "VZBRGITYUPSDNHLXAWMJQOFECK"},
                                                {6, "JPGVOUMFYQBENHZRDKASXLICTW"},
                                                {7, "NZJHGRCXMYSWBOUFAIVLPEKQDT"},
                                                {8, "FKQHTLXOCBJSPDZRAMEWNIUYGV"} };

    // These are positions where a rotor turns over the next rotor. 
    // ie rotor III turns over the next rotor when moving from 'V' to 'W'
    // A blank character is included because there is no 0 rotor so the string should be 1-indexed
    const std::string turnover = " QEVJZZZZ";

    // Keys are the names of the reflector
    // Values are the reflector mappings. So 'A' in reflector C maps to 'F'
    const std::map<unsigned char, std::string> reflectorMap = { {'A', "EJMZALYXVBWFCRQUONTSPIKHGD"},
                                                                {'B', "YRUHQSLDPXNGOKMIEBFZCWVJAT"}, 
                                                                {'C', "FVPJIAOYEDRZXWGCTKUQSBNMHL"} };
}


