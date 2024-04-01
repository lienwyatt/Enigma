

#include <chrono>
#include <iostream>
#include <conio.h>
#include <memory>

#include "KeypressProcessor.h"
#include "Enigma.h"
#include "RotorSettings.h"
#include "KeyboardInterface.h"
#include "HelperFunctions.h"
#include "RazerInit.h"


int main()
{

    helper::PrintAppDescription();

    //initalize the interface between this application and the keyboard 
    bool sucessfullyInitedChroma = (razerInit::InitializeKeyboard() == 0);
    std::unique_ptr<KeyboardInterface> keyboardInterface = nullptr;
    if (sucessfullyInitedChroma)
    {
        std::string ANIMATIONS_PATH = "Animations/";
        keyboardInterface = std::make_unique<KeyboardInterface>(ANIMATIONS_PATH);
    }

    // Get the enigma settings from the user
    EnigmaSettings settings = helper::GetDefaultEnigmaSettings();
    while (true)
    {
        std::cout << "Accept default Enigma settings? (y/n): ";
        char input = _getche();
        std::cout << std::endl;
        if (input == 'y' || input == 'Y')
        {
            break;
        }
        else if (input == 'n' || input == 'N')
        {
            settings = helper::GetEnigmaSettingsFromUser();
            break;
        }
        else
        {
            std::cout << "incorrect input" << std::endl;
        }
    }

    Enigma encryptor(settings);    
    helper::DisplayEnigmaSettings(settings);
    std::cout << std::endl << "Beginning Encryption" << std::endl << std::endl;

    //Begin listening to keypresses
    //register all alphabet keys as hotkeys
    KeypressProcessor keyProcessor;

    std::cout << "     Translation               Rotor Positions " << std::endl;
    std::cout << "    -------------             -----------------" << std::endl;

    //Wait for a Keypress. When a letter is pressed, encrypt it 
    // and display the cyphertext letter to the keyboard
    while (true)
    {
        unsigned char inputCharacter = keyProcessor.DetectKeypress();
        if ((inputCharacter >= 'A' && inputCharacter <= 'Z') || (inputCharacter >= 'a' && inputCharacter <= 'z'))
        {
            unsigned char result = encryptor.EncryptCharacter(inputCharacter);
            std::cout << "       " << inputCharacter << " --> " << result << "                     ";
            encryptor.PrintDisplay();

            // The application should be able to run even when no keyboard is used. 
            // So no warnings/errors when not actually displaying to keyboard.
            if (sucessfullyInitedChroma)
            {
                keyboardInterface->DisplayCharacter(result);
            }
        }
     }

    return 0;
}

