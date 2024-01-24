
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class Encryption
{
private:
	unsigned char firstRotorNumber,
	unsigned char secondRotorNumber,
	unsigned char ThirdRotorNumber,
	unsigned char firstRotorPosition,
	unsigned char secondRotorPosition,
	unsigned char ThirdRotorPosition,
public:
	Encryption(unsigned char firstRotorNumber,
			   unsigned char secondRotorNumber,
		       unsigned char ThirdRotorNumber,
			   unsigned char firstRotorPosition,
			   unsigned char secondRotorPosition,
			   unsigned char ThirdRotorPosition,
	char encryptCharacter(const char plaintextChar);
	std::string encryptString(const std::string& plaintextStr);
};

#endif //ENCRYPTION_H