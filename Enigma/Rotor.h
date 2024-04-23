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

#include <string>

#include "RotorSettings.h"

class Rotor
{
private:
    // 
    std::string mapping_;
    std::string inverseMapping_;
    unsigned char displayedCharacter_;
    unsigned int ringOffset_;
    unsigned char turnoverLetter_;

    // Generates inverseMapping_ of rotor based on mapping_
    void GenerateInverse();
public:
    Rotor(const RotorSettings& settings);


    Rotor();

    // Takes a letter passed into the rotor from right side
    // returns output letter from left side
    unsigned char Translate(unsigned char inputChar) const;
    
    // Takes a letter passed into the rotor from left side
    // returns output letter from right side
    unsigned char InverseTranslate(unsigned char inputChar) const;
    
    // rotates the rotor forward one position
    // returns the displayed character
    unsigned char Increment();

    // returns the position at which the rotor will turn over the next rotor
    unsigned char GetTurnoverLetter();

    // returns the letter currently being displayed by the rotor
    unsigned char GetCurrentLetter();

    // Makes the Rotor's internal wiring and turnover position match
    // the parameter. Sets the "Roman numeral"
    int UpdateRotorNumber(unsigned int rotorNumber);

};