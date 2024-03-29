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