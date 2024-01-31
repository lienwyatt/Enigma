
#pragma once

#include "Rotor.h"
#include "EnigmaSettings.h"

#include <string>
#include <map>

class Encryption
{
private:
	Rotor r1;
	Rotor r2;
	Rotor r3;
    std::map<unsigned char, unsigned char> plugboard;
	std::string reflector;
public:
	Encryption(const EnigmaSettings& initialSettings);
	unsigned char EncryptCharacter(const char plaintextChar);
	std::string EncryptString(const std::string& plaintextStr);
};
