
#include <string>
#include <iostream>

#include "Encryption.h"
#include "M3_Values.h"

Encryption::Encryption(const EnigmaSettings& initialSettings) : r1(initialSettings.r1),
                                                                r2(initialSettings.r2),
                                                                r3(initialSettings.r3),
                                                                plugboard(initialSettings.plugboard),
                                                                reflector(m3::reflectorMap.find(initialSettings.reflectorType)->second){}

unsigned char Encryption::EncryptCharacter(char plaintextChar)

{
    
    
    //pre-increment the first rotor. Continue incrementing the next 
    // if the previous rotor reached its cascade point
    bool incrementNextRotor = r1.Increment();
    if (incrementNextRotor)
    {
        incrementNextRotor = r2.Increment();
    }
    if (incrementNextRotor)
    {
        incrementNextRotor = r3.Increment();
    }
    
 
    unsigned char character = toupper(plaintextChar);
    std::cout << "translating pre-plugboard  " << character << std::endl;
    //the input character is sent through the plugboard
    if (plugboard.find(character) != plugboard.end())
    {
        character = plugboard[character];
    }
    std::cout << "translating  " << character << " to ";

    //the character is sent through the three rotors
    character = r1.Translate(character);
    std::cout << character << std::endl << "translating  " << character << " to ";
    character = r2.Translate(character);
    std::cout << character << std::endl << "translating  " << character << " to ";
    character = r3.Translate(character);
    std::cout << character << std::endl;

    std::cout << "reflecting " << character << " to " << reflector[character - 'A'] << std::endl;
    //send the character through the reflector
    character = reflector[character - 'A'];

    //send the character back through all three rotors
    std::cout << "translating  " << character << " to ";
    character = r3.InverseTranslate(character);
    std::cout << character << std::endl << "translating  " << character << " to ";
    character = r2.InverseTranslate(character);
    std::cout << character << std::endl << "translating  " << character << " to ";
    character = r1.InverseTranslate(character);
    std::cout << character << std::endl;

    std::cout << "Before plugboad " << character << std::endl;

    //send the result through the plugboard again
    if (plugboard.find(character) != plugboard.end())
    {
        character = plugboard[character];
    }

    std::cout << "result is " << character << std::endl;

    return character;
}


/*note that this function also performs a decryption when a 
ciphertext string is passed as a parameter*/
std::string Encryption::EncryptString(const std::string& plaintextStr)
{
    std::string ciphertextStr;

    for (const auto character : plaintextStr)
    {
        ciphertextStr += EncryptCharacter(character);
    }

    return ciphertextStr;
}
