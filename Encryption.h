
#pragma once

#include "Rotor.h"

#include <string>
#include <map>


struct Settings 
{
    unsigned int FirstRotorNumber;
    unsigned int SecondRotorNumber;
    unsigned int ThirdRotorNumber;
    unsigned int FirstRotorPosition;
    unsigned int SecondRotorPosition;
    unsigned int ThirdRotorPosition;
    std::map<unsigned char, unsigned char> plugboard;
};

class Encryption
{
private:
	Rotor r1;
	Rotor r2;
	Rotor r3;
public:
	Encryption(const Settings& initialSettings);
	unsigned char encryptCharacter(const char plaintextChar);
	std::string encryptString(const std::string& plaintextStr);
};
