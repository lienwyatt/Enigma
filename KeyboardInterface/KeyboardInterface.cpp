/*
 MIT License

Copyright (c) 2024 Wyatt Lien
Copyright (c) 2019 Razer, Inc.

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