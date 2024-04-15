
#pragma once

#include "KeyboardInterface.h"
#include "ChromaAnimationAPI.h"
#include <string>
#include <iostream>

//no prefix
const std::string KEYBOARD_POSTFIX = "_Keyboard.chroma";

// character used to display a blank keyboard animation. 
const char BLANK_ANIMATION_CHAR = '_';

const unsigned int KEY_DISPLAY_LENGTH_MS = 1000;


KeyboardInterface::KeyboardInterface(std::string filepath) : filePath_(filepath), postfix_(KEYBOARD_POSTFIX)
{
    timer_.Init(&KeyboardInterface::DisplayBlankKeyboardStatic, this, KEY_DISPLAY_LENGTH_MS);

    if (!ChromaSDK::ChromaAnimationAPI::GetIsInitializedAPI())
    {
        std::cerr << "KeyboardInterface(): No chroma API initialized" << std::endl;
    }
    DisplayBlankKeyboard();
}

void KeyboardInterface::DisplayCharacter(char c)
{
    std::string layout = filePath_ + c + postfix_;
    ChromaSDK::ChromaAnimationAPI::PlayAnimationName(layout.c_str(), true);

    //stop displaying the key after KEY_DISPLAY_LENGTH_NS
    timer_.Start();
}

void KeyboardInterface::DisplayBlankKeyboard()
{
    std::string layout = filePath_ + '_' + postfix_;
    ChromaSDK::ChromaAnimationAPI::PlayAnimationName(layout.c_str(), true);
}

void KeyboardInterface::DisplayBlankKeyboardStatic(void* thisPtr)
{
    KeyboardInterface* mePtr = static_cast<KeyboardInterface*>(thisPtr);
    mePtr->DisplayBlankKeyboard();
}

KeyboardInterface::~KeyboardInterface()
{
    try
    {
        timer_.~Timer();
        ChromaSDK::ChromaAnimationAPI::UninitAPI();
    }
    catch (...)
    {
        std::cout << "Error in KeyboardInterface destructor";
    }
}