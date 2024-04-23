/*
 MIT License

Copyright (c) 2024 Wyatt Lien

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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


