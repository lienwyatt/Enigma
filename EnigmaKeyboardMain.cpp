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

#include "KeypressProcessor.h"
#include "Enigma.h"
#include "RotorSettings.h"
#include "KeyboardInterface.h"
#include "HelperFunctions.h"
#include "RazerInit.h"
#include <chrono>
#include <iostream>
#include <conio.h>

int main()
{
    helper::PrintAppDescription();
    while (true)
    {
        // initalize the interface between this application and the keyboard 
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

        // Begin listening to keypresses
        // register all alphabet keys as hotkeys
        KeypressProcessor keyProcessor;
        std::string inputString;
        std::string outputString;

        std::cout << "     Translation               Rotor Positions " << std::endl;
        std::cout << "    -------------             -----------------" << std::endl;

        // Wait for a Keypress. When a letter is pressed, encrypt it 
        // and display the cyphertext letter to the keyboard
        while (true)
        {
            unsigned char inputCharacter = helper::ToUpper(keyProcessor.DetectKeypress());
            
            // if we receive an ESC key, print out encryption result then break from this loop and start over at the beginning of main()
            if (inputCharacter == ESC_KEY)
            {
                std::cout << "Escape key pressed. Ending Enigma.\n" << std::endl;
                std::cout << "Input text: " << std::endl << inputString << std::endl;
                std::cout << "Output text: " << std::endl << outputString << std::endl << std::endl;
                std::cout << "Press Enter to restart Enigma." << std::endl << std::endl;
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

