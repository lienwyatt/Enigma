# Enigma (In Progress)
Replicating the Enigma machine on an RGB Keyboard


## Background
The Enigma machine was a cipher device used to encode and decode German messages during WWII. The cypher was famously cracked by a team of codebreakers led by Alan Turing, helping the Allies to win WWII. For some good background on Enigma, check out [this video](https://www.youtube.com/watch?v=G2_Q9FoD-oQ).


## Objective
This project aims to replicate the behavior of the Enigma machine on a Razer BlackWidow Elite keyboard. An application should take initial rotor and plugboard settings as inputs and monitor for keypresses. Pressing any key will cause the corresponding cyphertext key  to light up on the keyboard. 


## Method
I plan to create a Windows application that takes in rotor and plugboard settings as inputs, then perfoms the relavent calculations to perform Enigma encryption. But how do I get the output cyphertext key to light up on the keyboard? Razer allows for creating custom keyboard color profiles through its Chroma Studio application, including ones that respond to key presses. Unfortunately, these all only feature keyboard color changes relating to the specific key pressed. This does not really help for this project, since I will need the cyphertext key to be different from the key pressed. Chroma Studio does allow for using the audio output of a PC as the input to a color profile. So I plan to create a custom keyboard profile that lights up a different key based on the audio volume being output from a PC. I can then make the windows application output a different volume tone to the system audio output for each key that is pressed. The custom keyboard profile will translate a system audio tone and know to light up a specific key. The end result will be a keyboard that behaves as an Enigma machine.

![Unmodified. Owner: Alessandro Nassiri, License: https://creativecommons.org/licenses/by-sa/4.0/deed.en](https://github.com/lienwyatt/Enigma/assets/31666811/2764f0cb-efd2-4033-b092-6303df1ddd70)
Photo by Alessandro Nassiri. Unmodified. Image License: https://creativecommons.org/licenses/by-sa/4.0/deed.en


