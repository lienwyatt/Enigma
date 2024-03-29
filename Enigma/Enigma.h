
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
