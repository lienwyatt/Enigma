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

#include "Enigma.h"
#include "M3_Constants.h"
#include <string>
#include <iostream>

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

    if (rightLetter == rightRotor_.GetTurnoverLetter() + 1 || (rightLetter == 'A' && rightRotor_.GetTurnoverLetter() == 'Z'))
    {
        //the other way the center rotor increments
        centerRotor_.Increment();
    }

 
    unsigned char character = toupper(plaintextChar);

    // the input character is sent through the plugboard
    if (plugboard_.find(character) != plugboard_.end())
    {
        character = plugboard_[character];
    }

    // the character is sent through the three rotors
    character = rightRotor_.Translate(character);
    character = centerRotor_.Translate(character);
    character = leftRotor_.Translate(character);

    // send the character through the reflector
    character = reflector_[character - 'A'];

    // send the character back therough the three rotors
    character = leftRotor_.InverseTranslate(character);
    character = centerRotor_.InverseTranslate(character);
    character = rightRotor_.InverseTranslate(character);

    if (plugboard_.find(character) != plugboard_.end())
    {
        character = plugboard_[character];
    }

    return character;
}


// note that this function also performs a decryption when a ciphertext string is passed as a parameter
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