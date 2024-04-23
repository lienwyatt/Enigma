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

#include <string>
#include "Timer.h"

class KeyboardInterface
{
private:
	// Relative path to chroma animations
	std::string filePath_;

	// timer class for restoring blank keyboard after a short period of time displaying a key. 
	Timer timer_;

	// string to follow output character in animation filename. Default is "_Keyboard.chroma"
	std::string postfix_;
public:
	// Constructor takes a relative path to the folder containing the animations for each letter.
	// Keyboard lights up with no letters highlighted
	KeyboardInterface(std::string filepath);

	// Destructor
	virtual ~KeyboardInterface();

	//  Displays the chroma animation corresponding to the character passed as a parameter. 
	// expects chroma animation relative path to be in the form <filePath_><c><postfix>
	void DisplayCharacter(char c);

	// Displays the blank keyboard animation
	void DisplayBlankKeyboard();

	// Displays the blank keyboard animation 
	static void DisplayBlankKeyboardStatic(void* thisPtr);
};
