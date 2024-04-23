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

#pragma once

#include "Rotor.h"
#include "EnigmaSettings.h"

#include <string>
#include <map>

class Enigma
{
private:
	Rotor rightRotor_;
	Rotor centerRotor_;
	Rotor leftRotor_;
	std::string reflector_;

	// requires a plugboard setting to be inserted in both directions
	// so plugboard_['A'] = 'E'; and plugboard_['E'] = 'A';
    std::map<unsigned char, unsigned char> plugboard_;
public:
	// Constructs an Enigma encrryptor object based on initial settings parameter
	Enigma(const EnigmaSettings& initialSettings);

	// Default constructor of Rotors sets ringletter and startingLetter to A
	// left rotor uses I
	// center rotor uses II
	// Right rotor uses III
	// Uses B-type reflector
	Enigma();

	// Encrypt a character according to Enigma. Increment all rotors accordingly
	// Returns Cyphertext character.
	unsigned char EncryptCharacter(const char plaintextChar);

	// Encrypt a string according to Enigma. Encrypt all rotors accordingly.
	// Returns Cyphertext string.
	std::string EncryptString(const std::string& plaintextStr);

	//prints to stdout the values of the rotor display characters
	void PrintDisplay();
};
