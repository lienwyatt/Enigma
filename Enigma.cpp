
#include <iostream>
#include "Encryption.h"

int main()
{
    Settings s;
    s.FirstRotorNumber = 1;
    s.FirstRotorPosition = 1;
    s.SecondRotorNumber = 1;
    s.SecondRotorPosition = 1;
    s.ThirdRotorNumber = 1;
    s.ThirdRotorPosition = 1;
    s.plugboard = {{'A', 'B'},
                   {'C', 'D'},
                   {'E', 'F'},
                   {'G', 'H'},
                   {'B', 'A'},
                   {'D', 'C'},
                   {'F', 'E'},
                   {'H', 'G'}, };

    
    Encryption encryptor(s);
    std::string word;
    while (std::cin >> word)
    {
        std::cout << "encrypting " << word << std::endl;
        std::cout << encryptor.encryptString(word) << std::endl;
        std::cout << "please enter another string " << std::endl;
        
    }
}

