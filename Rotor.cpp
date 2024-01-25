
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
    return mapping[inputChar - 'A'];
}

bool Rotor::increment()
{
    if (position == NUM_IN_ALPHABET - 1)
    {
        position = 0;
        return true;
    }
    position++;
    return false;
}
