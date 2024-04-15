#pragma once


#include "HelperFunctions.h"
#include "EnigmaSettings.h"
#include "RotorSettings.h"
#include <conio.h>
#include <unordered_set>

#include <iostream>

std::string helper::ToRoman(int digit)
{
    switch (digit)
    {
        case 1:
            return "I";
        case 2:
            return "II";
        case 3:
            return "III";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 6:
            return "VI";
        case 7:
            return "VII";
        case 8:
            return "VIII";
        case 9:
            return "IV";
        default:
            std::cerr << "Error: Bad input passed to ToRoman()";
            return "";
    }
}

unsigned char helper::ToUpper(unsigned char character)
{
    if (character >= 'a' && character <= 'z')
    {

        return 'A' - 'a' + character;
    }
    return character;
}

void helper::PrintAppDescription()
{
    
    std::cout << "Enigma Keyboard" << std::endl;
    std::cout << "Application developed by Wyatt Lien. For use with Razer Keyboards." << std::endl;
    std::cout << "Turn your keyboard into your very own Enigma machine!" << std::endl << std::endl;
}


void helper::DisplayEnigmaSettings(EnigmaSettings settings)
{
    std::cout << std::endl << std::endl << "Using the following settings:" << std::endl << std::endl;

    std::cout << "Reflector Type: " << settings.reflectorType << std::endl << std::endl;

    std::cout << "Plugboard Settings: ";

    std::unordered_set<char> printed;

    if (settings.plugboard.empty())
    {
        std::cout << "[none]";
    }
    else
    {
        std::cout << std::endl;
        for (const auto pair : settings.plugboard)
        {
            if (printed.find(pair.first) == printed.end() && printed.find(pair.second) == printed.end())
            {
                std::cout << pair.first << " <---> " << pair.second << std::endl;
                printed.insert(pair.first);
                printed.insert(pair.second);
            }
        }
    }
    std::cout << std::endl << std::endl;


    std::string leftNumeral = ToRoman(settings.leftRotor.rotorNumber);
    std::string centerNumeral = ToRoman(settings.centerRotor.rotorNumber);
    std::string rightNumeral = ToRoman(settings.rightRotor.rotorNumber);
    std::cout << "              left rotor       center rotor        right rotor" << std::endl;

    std::cout << "Rotor Number:     " << leftNumeral;
    //justify text
    for (int i = 0; i < (3 - leftNumeral.size()); i++)
    {
        std::cout << " ";
    }
    std::cout << "                " << centerNumeral;
    for (int i = 0; i < (3 - centerNumeral.size()); i++)
    {
        std::cout << " ";
    }
    std::cout << "                " << rightNumeral << std::endl;


    std::cout << "Ring setting:     " << settings.leftRotor.ringLetter     << "                  " << settings.centerRotor.ringLetter     << "                  " << settings.rightRotor.ringLetter << std::endl;
    std::cout << "Starting Letter:  " << settings.leftRotor.startingLetter << "                  " << settings.centerRotor.startingLetter << "                  " << settings.rightRotor.startingLetter << std::endl;
}

EnigmaSettings helper::GetDefaultEnigmaSettings()
{
    EnigmaSettings enigmaSettings;
    RotorSettings rotorSettings;

    rotorSettings.ringLetter = 'A';
    rotorSettings.startingLetter = 'A';

    rotorSettings.rotorNumber = 1;
    enigmaSettings.leftRotor = rotorSettings;

    rotorSettings.rotorNumber = 2;
    enigmaSettings.centerRotor = rotorSettings;

    rotorSettings.rotorNumber = 3;
    enigmaSettings.rightRotor = rotorSettings;

    enigmaSettings.plugboard = {};

    enigmaSettings.reflectorType = 'B';

    return enigmaSettings;
}

EnigmaSettings helper::GetEnigmaSettingsFromUser()
{

    unsigned char input;

    //default constructor makes an empty plugboard, 
    EnigmaSettings settings;

    std::cout << "Manual setup chosen. Hit the space bar at any time to begin encryption." << std::endl;

    // Prompt the user to choose a rotor number.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a rotor number for the left rotor (1-5): ";
        input = _getche();
        std::cout << std::endl;
        if (input >= '1' && input <= '5')
        {
            settings.leftRotor.rotorNumber = input - '0';
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a rotor number.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a rotor number for the center rotor(1-5): ";
        input = _getche();
        std::cout << std::endl;
        if (input >= '1' && input <= '5')
        {
            settings.centerRotor.rotorNumber = input - '0';
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a rotor number.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a rotor number for the right rotor (1-5): ";
        input = _getche();
        std::cout << std::endl;

        if (input >= '1' && input <= '5')
        {
            settings.rightRotor.rotorNumber = input - '0';
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a starting letter.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a starting letter for the left rotor (A-Z): ";
        input = _getche();
        std::cout << std::endl;
        if (input >= 'A' && input <= 'Z')
        {
            settings.leftRotor.startingLetter = input;
            break;
        }
        else if (input >= 'a' && input <= 'z')
        {
            input += 'A' - 'a';
            settings.leftRotor.startingLetter = input;
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a starting letter.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a starting letter for the center rotor (A-Z): ";
        input = _getche();
        std::cout << std::endl;

        if (input >= 'A' && input <= 'Z')
        {
            settings.centerRotor.startingLetter = input;
            break;
        }
        else if (input >= 'a' && input <= 'z')
        {
            input += 'A' - 'a';
            settings.centerRotor.startingLetter = input;
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a starting letter.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a starting letter for the right rotor (A-Z): ";
        input = _getche();
        std::cout << std::endl;

        if (input >= 'A' && input <= 'Z')
        {
            settings.rightRotor.startingLetter = input;
            break;
        }
        else if (input >= 'a' && input <= 'z')
        {
            input += 'A' - 'a';
            settings.rightRotor.startingLetter = input;
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a Ring Setting.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a ring setting for the left rotor (A-Z): ";
        input = _getche();
        std::cout << std::endl;

        if (input >= 'A' && input <= 'Z')
        {
            settings.leftRotor.ringLetter = input;
            break;
        }
        else if (input >= 'a' && input <= 'z')
        {
            input += 'A' - 'a';
            settings.leftRotor.ringLetter = input;
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a Ring Setting.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a ring setting for the center rotor (A-Z): ";
        input = _getche();
        std::cout << std::endl;

        if (input >= 'A' && input <= 'Z')
        {
            settings.centerRotor.ringLetter = input;
            break;
        }
        else if (input >= 'a' && input <= 'z')
        {
            input += 'A' - 'a';
            settings.centerRotor.ringLetter = input;
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a Ring Setting.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a ring setting for the right rotor (A-Z): ";
        input = _getche();
        std::cout << std::endl;

        if (input >= 'A' && input <= 'Z')
        {
            settings.rightRotor.ringLetter = input;
            break;
        }
        else if (input >= 'a' && input <= 'z')
        {
            input += 'A' - 'a';
            settings.rightRotor.ringLetter = input;
            break;
        }
        else if (input == ' ')
        {
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a Reflector.
    // If space bar is pressed proceed to encrytion.
    while (true)
    {
        std::cout << "Choose a reflector model (B or C): ";
        input = _getche();

        std::cout << std::endl;
        if (input == 'B' || input == 'b')
        {
            settings.reflectorType = 'B';
            break;
        }
        if (input == 'C' || input == 'c')
        {
            settings.reflectorType = 'C';
            break;
        }
        else if (input == ' ')
        { 
            return settings;
        }
        else
        {
            std::cout << "Incorrect input" << std::endl;
        }
    }

    // Prompt the user to choose a Reflector.
    // If space bar is pressed proceed to encrytion.
    unsigned char key1;
    unsigned char key2;
    std::cout << "Press space to begin enigma. " << std::endl;
    while (true)
    {
        std::cout << "Press two keys (A-Z) to add a unique pair to the plugboard: ";

        key1 = _getche();
        std::cout << " ";

        if (key1 == ' ')
        {
            break;
        }
        key2 = _getche();
        std::cout << std::endl;

        if (key2 == ' ')
        {
            break;
        }

        //capitalize
        key1 = ToUpper(key1);

        //capitalize
        key2 = ToUpper(key2);

        if (key1 == key2)
        {
            std::cout << "Keys must be different" << std::endl;
            continue;
        }

        if (key1 < 'A' || key2 > 'Z')
        {
            std::cout << "Incorrect input" << std::endl;
            continue;
        }

        //if key has been used yet
        if ((settings.plugboard.find(key1) == settings.plugboard.end()) && (settings.plugboard.find(key2) == settings.plugboard.end()))
        {

            settings.plugboard[key1] = key2;
            settings.plugboard[key2] = key1;
            std::cout << "Pair added." << std::endl;
        }
        else
        {
            std::cout << "Keys may only be used in plugboard once" << std::endl;
        }
        if (settings.plugboard.size() == 20)
        {
            // in general 10 was the max number of plugboard connections used, even though there was a theoretical limit of 13
            // each pair is added twice
            std::cout << "max plugboard size reached" << std::endl;
            break;
        }
    }
    return settings;
}

