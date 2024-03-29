
#include "EnigmaSettings.h"
#include "ChromaAnimationAPI.h"

#include <string>

namespace helper
{
    // converts a single-digit number to roman numerals
    // input number should be from 1-9
    std::string ToRoman(int numChar);

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