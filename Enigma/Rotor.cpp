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

#include "Rotor.h"
#include "M3_Constants.h"
#include <string>
#include <iostream>

const int NUM_CHARS_IN_ALPHABET = 26;


Rotor::Rotor(const RotorSettings& settings) : displayedCharacter_(settings.startingLetter),
                                              ringOffset_(settings.ringLetter - 'A'),
                                              mapping_(m3::rotors.find(settings.rotorNumber)->second),
                                              turnoverLetter_(m3::turnover[settings.rotorNumber])
{
    GenerateInverse();
}

Rotor::Rotor() : mapping_(m3::rotors.find(1)->second),
                 turnoverLetter_(m3::turnover[1]),
                 displayedCharacter_('A'),
                 ringOffset_(0)
{
    GenerateInverse();
}

int Rotor::UpdateRotorNumber(unsigned int rotorNumber)
{
    if (rotorNumber > 5 || rotorNumber < 1)
    {
        std::cerr << "Incorrect value " << rotorNumber << " passed to Rotor::UpdateRotorNumber" << std::endl;
        return -1;
    }
    mapping_ = m3::rotors.find(rotorNumber)->second;
    turnoverLetter_ = m3::turnover[rotorNumber];

    GenerateInverse();

    return 0;
}

unsigned char Rotor::Translate(unsigned char inputChar) const
{

    if (inputChar > 'Z' || inputChar < 'A')
    {
        std::cerr << "incorrect character " << inputChar << " passed to Rotor::Translate()" << std::endl;
    }

    // increasing the input character, ring offset and displayed character will all cause the wiring input to change proportionally
    // need to subtract 'A' from inputChar and displayedCharacter so that we get a numerical offset and not an ASCII value
    unsigned int wiringInput = ((inputChar - 'A') + (displayedCharacter_ - 'A') - ringOffset_ + NUM_CHARS_IN_ALPHABET) % NUM_CHARS_IN_ALPHABET;

    //differece between input and output of wiring
    int wiringOffset = mapping_[wiringInput];

    // now convert wiringOffset to an output value. Since wiringOffset can be negative, 
    // add the number of characters in the alphabet then mod by it and renormalize at A
    return (wiringOffset - (displayedCharacter_ - 'A') - 'A' + ringOffset_ + NUM_CHARS_IN_ALPHABET) % NUM_CHARS_IN_ALPHABET + 'A';
}

unsigned char Rotor::InverseTranslate(unsigned char inputChar) const
{
    if (inputChar > 'Z' || inputChar < 'A')
    {
        std::cerr << "incorrect character " << inputChar << " passed to Rotor::InverseTranslate()" << std::endl;
    }

    // increasing the input character, ring offset and displayed character will all cause the wiring input to change proportionally
    // need to subtract 'A' from inputChar and displayedCharacter so that we get a numerical offset and not an ASCII value
    unsigned int wiringInput = ((inputChar - 'A') + (displayedCharacter_ - 'A') - ringOffset_ + NUM_CHARS_IN_ALPHABET) % NUM_CHARS_IN_ALPHABET;

    //differece between input and output of wiring
    int wiringOffset = inverseMapping_[wiringInput];

    // now convert wiringOffset to an output value. Since wiringOffset can be negative, 
    // add the number of characters in the alphabet then mod by it and renormalize at A
    return (wiringOffset - (displayedCharacter_ - 'A') - 'A' + ringOffset_ + NUM_CHARS_IN_ALPHABET) % NUM_CHARS_IN_ALPHABET + 'A';
}

unsigned char Rotor::Increment()
{
    displayedCharacter_++;
    displayedCharacter_ = (displayedCharacter_ - 'A') % NUM_CHARS_IN_ALPHABET + 'A';


    return displayedCharacter_;
}

void Rotor::GenerateInverse()
{
    //dummy string to be filled. Should have size of the alphabet. 
    inverseMapping_ = std::string(NUM_CHARS_IN_ALPHABET, ' ');

    for (int i = 0; i < mapping_.size(); i++)
    {
        // if C is at the 0th position in the mapping array, A would be at the 2nd position in the inverse array
        inverseMapping_[mapping_[i] - 'A'] = 'A' + i;
    }
}


unsigned char Rotor::GetTurnoverLetter()
{
    return turnoverLetter_;
}

unsigned char Rotor::GetCurrentLetter()
{
    return displayedCharacter_;
}