
#include <string>
#include <iostream>

#include "Enigma.h"
#include "M3_Constants.h"

Enigma::Enigma(const EnigmaSettings& initialSettings) : rightRotor_(initialSettings.rightRotor),
                                                        centerRotor_(initialSettings.centerRotor),
                                                        leftRotor_(initialSettings.leftRotor),
                                                        plugboard_(initialSettings.plugboard),
                                                        reflector_(m3::reflectorMap.find(initialSettings.reflectorType)->second)
{}


Enigma::Enigma() : reflector_(m3::reflectorMap.find('B')->second),
                   plugboard_({})
{
    //Default constructor of Rotors sets ringletter and startingLetter to A

    //left rotor uses I
    leftRotor_.UpdateRotorNumber(1);

    //center rotor uses II
    centerRotor_.UpdateRotorNumber(2);
    
    //Right rotor uses III
    rightRotor_.UpdateRotorNumber(3);
}


unsigned char Enigma::EncryptCharacter(char plaintextChar)

{
    //pre-increment the first rotor each time. Also increment 
    //the next if the rotor reached its cascade point
    unsigned char rightLetter = rightRotor_.Increment();

    //The double-step is a quirk of the M1 Enigma design.
    //rather than turning over the leftmost rotor immediately, 
    //the middle rotor actually increments twice in a row, turning the 
    //leftmost rotor on the second increment.
    unsigned char centerLetter = centerRotor_.GetCurrentLetter();
    if (centerLetter == centerRotor_.GetTurnoverLetter())
    {
        //immediately increment both the center and left rotor on the next translation
        centerRotor_.Increment();
        leftRotor_.Increment();
    }

    if (rightLetter == rightRotor_.GetTurnoverLetter())
    {
        //the other way the center rotor increments
        centerRotor_.Increment();
    }

 
    unsigned char character = toupper(plaintextChar);
    //std::cout << "translating pre-plugboard  " << character << std::endl;
    //the input character is sent through the plugboard
    if (plugboard_.find(character) != plugboard_.end())
    {
        character = plugboard_[character];
    }
    //std::cout << std::endl << "translating  " << character << std::endl;

    //the character is sent through the three rotors
    character = rightRotor_.Translate(character);
    //std::cout << " result " << character << std::endl << "translating  " << character << std::endl;
    character = centerRotor_.Translate(character);
    //std::cout << " result " << character << std::endl << "translating  " << character << std::endl;
    character = leftRotor_.Translate(character);
    //std::cout << " result " << character << std::endl;

    //std::cout << "reflecting " << character << " to " << reflector_[character - 'A'] << std::endl;
    //send the character through the reflector
    character = reflector_[character - 'A'];

    //send the character back through all three rotors in the opposite direction
    //std::cout << "translating  " << character << std::endl;
    character = leftRotor_.InverseTranslate(character);
    //std::cout << " result " << character << std::endl << "translating  " << character << std::endl;
    character = centerRotor_.InverseTranslate(character);
    //std::cout << " result " << character << std::endl << "translating  " << character << std::endl;
    character = rightRotor_.InverseTranslate(character);
    //std::cout << " result " << character << std::endl;

    //std::cout << "Before plugboad " << character << std::endl;
    if (plugboard_.find(character) != plugboard_.end())
    {
        character = plugboard_[character];
    }

    //std::cout << "result is " << character << std::endl;

    return character;
}


//note that this function also performs a decryption when a 
//ciphertext string is passed as a parameter
std::string Enigma::EncryptString(const std::string& plaintextStr)
{
    std::string ciphertextStr;

    for (const auto character : plaintextStr)
    {
        ciphertextStr += EncryptCharacter(character);
    }

    return ciphertextStr;
}


void Enigma::PrintDisplay()
{
    std::cout << "|" << leftRotor_.GetCurrentLetter() << "|" << centerRotor_.GetCurrentLetter() << "|" << rightRotor_.GetCurrentLetter() << "|" <<std::endl;
}