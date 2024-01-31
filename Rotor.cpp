
#include <string>
#include <iostream>

#include "Rotor.h"
#include "Encryption.h"
#include "M3_Values.h"

Rotor::Rotor(const RotorSettings& settings) : position(settings.startingPosition), 
                                              ringSetting(settings.ringSetting),
                                              mapping(m3::rotors.find(settings.rotorNumber)->second)
{
    GenerateInverse();
}

unsigned char Rotor::Translate(unsigned char inputChar) const
{
    
    if (inputChar > 'Z' || inputChar < 'A')
    {
        std::cout << "incorrect character " << inputChar << " passed to Rotor::Translate()" << std::endl;
    }
    //example: E would return the 4th (0 indexed) character in the mapping
    //std::cout << "translating " << ((inputChar + position) % NUM_CHARS_IN_ALPHABET) << " - A which comes out to " << ((inputChar + position) % NUM_CHARS_IN_ALPHABET) - 'A' << std::endl;

    //the 0th item in mapping is what A maps to. Translate whichever character is entered and shift the amount the rotor has turned. 
    //std::cout << "translated " << inputChar << " to " << mapping[(inputChar - 'A' + position) % NUM_CHARS_IN_ALPHABET] << std::endl;
    return mapping[(inputChar - 'A' + position) % NUM_CHARS_IN_ALPHABET];
}

unsigned char Rotor::InverseTranslate(unsigned char inputChar) const
{
    //std::cout << "about to translate char " << inputChar << std::endl;
    if (inputChar > 'Z' || inputChar < 'A')
    {
        std::cout << "incorrect character " << inputChar << " passed to Rotor::InverseTranslate()" << std::endl;
    }
    //example: E would return the 4th (0 indexed) character in the mapping
    //std::cout << "translting " << ((inputChar + position) % NUM_CHARS_IN_ALPHABET) << " - A which comes out to " << ((inputChar + position) % NUM_CHARS_IN_ALPHABET) - 'A' << std::endl;

    //the 0th item in mapping is what A maps to. Translate whichever character is entered and shift the amount the rotor has turned. 
    return inverseMapping[(inputChar - 'A' + position) % NUM_CHARS_IN_ALPHABET];
}

bool Rotor::Increment()
{
    position++;
    position = position % NUM_CHARS_IN_ALPHABET;
    if (position == 0)
    {
        return true;
    }
    return false;
}

void Rotor::GenerateInverse()
{
    inverseMapping = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < mapping.size(); i++)
    {
        //if C is at the 0th position in the mapping array, A would be at the 2nd position in the inverse array
        inverseMapping[mapping[i] - 'A'] = 'A' + i;
        //std::cout << "added " << i + 'A' << " to position " << mapping[i] << std::endl;
    }
    std::cout << "Generated inverse: " << inverseMapping << std::endl;
}