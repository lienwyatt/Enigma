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

#include "EnigmaSettings.h"
#include "ChromaAnimationAPI.h"

#include <string>

namespace helper
{
    // converts a single-digit number to roman numerals
    // input number should be from 1-9
    std::string ToRoman(int numChar);

    // converts lowercase characters to uppercase
    // returns the original character if not lowercase
    unsigned char ToUpper(unsigned char character);

    // prints description of the Enigma Keyboard application
    void PrintAppDescription();

    //Returns Default Enigma Settings as an EnigmaSettings object
    // Default Display letter of each rotor to A
    // No ring offset
    // Rotors from left to right are I, II, III
    // Uses B-type reflector
    EnigmaSettings GetDefaultEnigmaSettings();

    //Prompts the user for Enigma Settings
    // returns the result as an EnigmaSettings object
    EnigmaSettings GetEnigmaSettingsFromUser();

    // Prints the Enigma settings passed as a parameter
    void DisplayEnigmaSettings(EnigmaSettings settings);
}