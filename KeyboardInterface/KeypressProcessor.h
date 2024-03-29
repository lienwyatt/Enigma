#pragma once


class KeypressProcessor
{
private:
    bool initialized_;
public:
    // Constructor
    KeypressProcessor();

    // Destructor
    ~KeypressProcessor();

    // Blocks until keypress occurs. Captures only letter keypresses and SHIFT+letter keypresses.
    // Returns a captured character from a keypress. Keypress value is still passed to OS. 
    unsigned char DetectKeypress();
};