
#include <string>
#include <iostream>

#include "Rotor.h"
#include "M3_Constants.h"


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

    //increasing the input character, ring offset and displayed character will all cause the wiring input to change proportionally
    //need to subtract 'A' from inputChar and displayedCharacter so that we get a numerical offset and not an ASCII value
    unsigned int wiringInput = ((inputChar - 'A') + (displayedCharacter_ - 'A') - ringOffset_ + NUM_CHARS_IN_ALPHABET) % NUM_CHARS_IN_ALPHABET;
    //std::cout << std::endl << "displayedChar " << displayedCharacter_ << std::endl;
    //std::cout << std::endl << "inputChar " << inputChar << std::endl;
    //printf("wiringInputOffset to be mapped %c\n", wiringInput + 'A');

    //differece between input and output of wiring
    int wiringOffset = mapping_[wiringInput];
    //printf("output of map %c\n", wiringOffset);
    //printf("sum %c\n", wiringOffset + (displayedCharacter_ - 'A'));
    //printf("diff %c\n", wiringOffset - (displayedCharacter_ - 'A'));

    //now convert wiringOffset to an output value. Since wiringOffset can be negative, 
    //add the number of characters in the alphabet then mod by it and renormalize at A
    return (wiringOffset - (displayedCharacter_ - 'A') - 'A' + ringOffset_ + NUM_CHARS_IN_ALPHABET) % NUM_CHARS_IN_ALPHABET + 'A';
}

unsigned char Rotor::InverseTranslate(unsigned char inputChar) const
{
    if (inputChar > 'Z' || inputChar < 'A')
    {
        std::cerr << "incorrect character " << inputChar << " passed to Rotor::InverseTranslate()" << std::endl;
    }

    unsigned int wiringInput = ((inputChar - 'A') + (displayedCharacter_ - 'A') - ringOffset_ + NUM_CHARS_IN_ALPHABET) % NUM_CHARS_IN_ALPHABET;

    int wiringOffset = inverseMapping_[wiringInput];

    return (wiringOffset - (displayedCharacter_ - 'A') - 'A' + ringOffset_ + NUM_CHARS_IN_ALPHABET) % NUM_CHARS_IN_ALPHABET + 'A';
}

unsigned char Rotor::Increment()
{

    //std::cout << std::endl << "displayedChar " << displayedCharacter_ << std::endl;
    displayedCharacter_++;
    displayedCharacter_ = (displayedCharacter_ - 'A') % NUM_CHARS_IN_ALPHABET + 'A';
    //std::cout << std::endl << "displayedChar " << displayedCharacter_ << std::endl;


    return displayedCharacter_;
}

void Rotor::GenerateInverse()
{
    //dummy string to be filled. Should have size of the alphabet. 
    inverseMapping_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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