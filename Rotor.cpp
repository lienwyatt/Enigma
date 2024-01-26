
#include <string>
#include <iostream>

#include "Rotor.h"
#include "Encryption.h"

Rotor::Rotor(const std::string& letters, int startingPosition) : mapping(letters), position(startingPosition) {}


unsigned char Rotor::translate(unsigned char inputChar) const
{
    //std::cout << "about to translate char " << inputChar << std::endl;
    if (inputChar > 'Z' || inputChar < 'A')
    {
        std::cout << "incorrect character " << inputChar << " passed to Rotor::translate()" << std::endl;
    }
    //example: E would return the 4th (0 indexed) character in the mapping
    //std::cout << "translting " << ((inputChar + position) % NUM_IN_ALPHABET) << " - A which comes out to " << ((inputChar + position) % NUM_IN_ALPHABET) - 'A' << std::endl;

    //the 0th item in mapping is what A maps to. Translate whichever character is entered and shift the amount the rotor has turned. 
    return mapping[(inputChar - 'A' + position) % NUM_IN_ALPHABET];
}

bool Rotor::increment()
{
    position++;
    position = position % NUM_IN_ALPHABET;
    if (position == 0)
    {
        return true;
    }
    return false;
}
