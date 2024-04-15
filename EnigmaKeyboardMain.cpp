

#include <chrono>
#include <iostream>
#include <conio.h>
#include <chrono>
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
    while (true)
    {

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
            char input = helper::ToUpper(_getche());
            std::cout << std::endl;
            if (input == 'Y')
            {
                break;
            }
            else if (input == 'N')
            {
                settings = helper::GetEnigmaSettingsFromUser();
                break;
            }
            else
            {
                std::cout << "Incorrect input." << std::endl;
            }
        }

        Enigma encryptor(settings);
        helper::DisplayEnigmaSettings(settings);
        std::cout << std::endl << "Beginning Encryption. Press ESC at any time to change settings." << std::endl << std::endl;

        //Begin listening to keypresses
        //register all alphabet keys as hotkeys
        KeypressProcessor keyProcessor;

        std::cout << "     Translation               Rotor Positions " << std::endl;
        std::cout << "    -------------             -----------------" << std::endl;

        std::string inputString;
        std::string outputString;


        //Wait for a Keypress. When a letter is pressed, encrypt it 
        // and display the cyphertext letter to the keyboard
        while (true)
        {
            unsigned char inputCharacter = helper::ToUpper(keyProcessor.DetectKeypress());
            
            // if we receive an ESC key, print out encryption result then break from this loop and start over at the beginning of main()
            // Then flush the std::cin buffer. Without doing this, previous characters get re-entered.
            if (inputCharacter == ESC_KEY)
            {
                std::cout << "Escape key pressed. Ending encryption.\n" << std::endl;
                std::cout << "Input text: " << std::endl << inputString << std::endl;
                std::cout << "Output text: " << std::endl << outputString << std::endl;
                std::cout << "Beginning new encryption" << std::endl << std::endl;

                // this is a pretty ridiculous way of clearing the input buffer, but it is needed because we can't actaully tell how long it is.
                // because we want this to work whether or not you are typing in the window, there can be various sizes of this buffer. 
                //std::chrono::time_point<std::chrono::system_clock> endTime = std::chrono::system_clock::now() + std::chrono::milliseconds(50);
                //while (std::chrono::system_clock::now() <= endTime)
                //{
                //   _getch();
                //}
                
                std::cin.ignore(INT_MAX, '\n');
                break;
            }
            if (inputCharacter >= 'A' && inputCharacter <= 'Z')
            {
                inputString += inputCharacter;
                unsigned char result = encryptor.EncryptCharacter(inputCharacter);
                outputString += result;
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
    }
    // should never arrive here
    return -1;
}

