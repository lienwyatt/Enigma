
#include <iostream>
#include "Encryption.h"

int main()
{
    RotorSettings r;
    r.ringSetting = 0;
    r.startingPosition = 0;
    r.rotorNumber = 1;
    EnigmaSettings s;
    s.r1 = r;
    r.rotorNumber = 2;
    s.r2 = r;
    r.rotorNumber = 3;
    s.r3 = r;
    s.plugboard = {{'A', 'B'},
                   {'C', 'D'},
                   {'E', 'F'},
                   {'G', 'H'},
                   {'B', 'A'},
                   {'D', 'C'},
                   {'F', 'E'},
                   {'H', 'G'}};
    s.reflectorType = 'B';

    
    Encryption encryptor(s);
    std::string word;
    std::cout << "please enter a string ";
    while (std::cin >> word)
    {
        std::cout << "encrypting " << word << std::endl;
        std::cout << encryptor.EncryptString(word) << std::endl;
        std::cout << "please enter another string " << std::endl;
        
    }
}

