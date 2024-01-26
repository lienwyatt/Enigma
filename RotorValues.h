#pragma once

/*
const std::string I   = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
const std::string II  = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
const std::string III = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
const std::string IV  = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
const std::string V   = "VZBRGITYUPSDNHLXAWMJQOFECK";
*/

#include <vector>

//leave the first entry blank so that rotors can be accessed by their assigned number
//aka the vector needs to be 1-indexed 
const std::vector<std::string> rotors =
{
    "",
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
    "ESOVPZJAYQUIRHXLNFTGKDCMWB",
    "VZBRGITYUPSDNHLXAWMJQOFECK"
};


