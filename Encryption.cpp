
#include <string>

#include "Encryption.h"
#include "RotorValues.h"

Encryption::Encryption(const Settings& initialSettings) :
    r1(rotors[initialSettings.FirstRotorNumber], initialSettings.FirstRotorNumber),
    r2(rotors[initialSettings.SecondRotorNumber], initialSettings.SecondRotorPosition),
    r3(rotors[initialSettings.ThirdRotorNumber], initialSettings.ThirdRotorPosition)
{}

unsigned char Encryption::encryptCharacter(char plaintextChar)
{
    unsigned char character = toupper(plaintextChar);
    //pre-increment the rotor.
    bool incrementNextRotor = r1.increment();
    character = r1.translate(character);
    //If the preceeding rotor overruns, increment the next one too
    if (incrementNextRotor)
    {
        incrementNextRotor = r2.increment();
    }
    character = r2.translate(character);
    if (incrementNextRotor)
    {
        incrementNextRotor = r3.increment();
    }
    return r3.translate(character);
}


/*note that this function also performs a decryption when a 
ciphertext string is passed as a parameter*/
std::string Encryption::encryptString(const std::string& plaintextStr)
{
    std::string ciphertextStr;

    for (const auto character : plaintextStr)
    {
        ciphertextStr += encryptCharacter(character);
    }

    return ciphertextStr;
}
