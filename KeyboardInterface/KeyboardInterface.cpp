
#pragma once

#include "KeyboardInterface.h"
#include "ChromaAnimationAPI.h"
#include <string>
#include <iostream>

//no prefix
const std::string KEYBOARD_POSTFIX = "_Keyboard.chroma";

// character used to display a blank keyboard animation. 
const char BLANK_ANIMATION_CHAR = '_';


KeyboardInterface::KeyboardInterface(std::string filepath) : filePath_(filepath), postfix_(KEYBOARD_POSTFIX)
{
    ChromaSDK::ChromaAnimationAPI::InitAPI();
    if (!ChromaSDK::ChromaAnimationAPI::GetIsInitializedAPI())
    {
        std::cerr << "failed to init API" << std::endl;
    }
    DisplayBlankKeyboard();
}

void KeyboardInterface::DisplayCharacter(char c)
{
    std::string layout = filePath_ + c + postfix_;
    ChromaSDK::ChromaAnimationAPI::PlayAnimationName(layout.c_str(), true);
}

void KeyboardInterface::DisplayBlankKeyboard()
{
    DisplayCharacter(BLANK_ANIMATION_CHAR);
}

KeyboardInterface::~KeyboardInterface()
{
    ChromaSDK::ChromaAnimationAPI::UninitAPI();
}