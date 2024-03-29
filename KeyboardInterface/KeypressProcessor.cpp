#include "KeypressProcessor.h"
#include "windows.h"
#include <iostream>


//semi-arbitrary value to add to IDs to make it clear which IDs had [SHIFT] key pressed
const int SHIFT_ID_OFFSET = 100;

KeypressProcessor::KeypressProcessor() : initialized_(false)
{
    try 
    {
        char character = 'A';
        while (character <= 'Z')
        {
            INPUT input;
            ZeroMemory(&input, sizeof(input));
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = character;

            //use character as the ID 
            RegisterHotKey(NULL, character, 0, character);

            //we also need to make sure that typing a capital letter doesnt break stuff. 
            //That means pressing shift at the same time should also be registered as a hotkey.
            RegisterHotKey(NULL, character + SHIFT_ID_OFFSET, MOD_SHIFT, character);

            character += 1;
        }
        initialized_ = true;
    }
    catch (...)
    {
        std::cerr << "error in KepressProcessor init" << std::endl;
    }
    
}

KeypressProcessor::~KeypressProcessor()
{
    char character = 'A';
    while (character <= 'Z')
    {
        try
        {
            INPUT input;
            ZeroMemory(&input, sizeof(input));
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = character;

            //use character as the ID 
            UnregisterHotKey(NULL, character);

            //make sure to add an offset to the ID for a press with [SHIFT] held down
            UnregisterHotKey(NULL, character + SHIFT_ID_OFFSET);

            character += 1;
        }
        catch (...)
        {
            std::cerr << "error in KepressProcessor uninit" << std::endl;
        }
    }
}

unsigned char KeypressProcessor::DetectKeypress()
{
    MSG message;

    //initialize to arbitrary default
    char nextChar = '0';

    while (GetMessage(&message, NULL, 0, 0))
    {
        if (message.message == WM_HOTKEY)
        {
            //if the 4 bit was set, shift was pressed
            bool shiftPressed = static_cast<bool>(message.lParam & 0x0004);

            //the character is stored in the left bits of the lParam member variable in the message
            unsigned char character = static_cast<char>((message.lParam | 0xFF00) >> 16);

            INPUT input;
            ZeroMemory(&input, sizeof(input));
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = character;

            // if the hotkey were still registered when SendInput() was called, 
            // then it would create an infinite loop because it would also trigger the hotkey. 
            // Temporarily unregister it. 
            if (shiftPressed)
            {
                UnregisterHotKey(NULL, character + SHIFT_ID_OFFSET);
            }
            else
            {
                UnregisterHotKey(NULL, character);
            }
            
            //duplicate the key pressed because the hotkey will not actually pass the value to the OS
            SendInput(1, &input, sizeof(input));

            //now the hotkey can be re-registered.
            if (shiftPressed)
            {
                RegisterHotKey(NULL, character + SHIFT_ID_OFFSET, MOD_SHIFT, character);
            }
            else
            {
                RegisterHotKey(NULL, character, 0, character);
            }
            
            return character;
        }
    }
}