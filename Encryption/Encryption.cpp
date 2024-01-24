
#include <string>

#include "Rotors.h"
#include "Encryption.h"

char Encryption::encryptCharacter(const char plainTextChar)
{

}


/*note that this function also performs a decryption when a 
ciphertext string is passed as a parameter*/
std::string Encryption::encryptString(const std::string& plaintextStr)
{
    std::string ciphertextStr;

    for (const auto character : plainTextStr)
    {
        cipherTextString += encryptCharacter(character);
    }

    return cipherTextString
}
