# Enigma Keyboard

## Objective
This application allows the user to replicate the behavior of the Enigma machine on a Razer keyboard. When a key is pressed, the corresponding encrypted cyphertext letter lights up on the keyboard. A window launches where Enigma settings can be customized. The window can then be minimized and the encryption will continue to display on the keyboard while other applications are used. 

## Background
The Enigma machine was a cipher device used to encode and decode German messages during WWII. The cipher was famously cracked by a team of codebreakers led by Alan Turing, helping the Allies to win WWII. For some good background on Enigma, check out [this video](https://www.youtube.com/watch?v=G2_Q9FoD-oQ). Because a pressed key never encrypts to itself in enigma, You should always see a key light up when pressed. 

## Method
Each key is registered as a hotkey to detect keypresses. This allows the keyboard to continue displaying the encrypted letters while using other applications. A different Chroma animation was created for each letter using the online [Chroma Editor](https://chroma.razer.com/ChromaEditor/). Swapping between these animations was done done via the C++ Chroma API released by the Razer keyboard manufacturer. The sample app found [here](https://github.com/razerofficial/CSDK_SampleApp) allows for displaying animations to the keyboard and was adapted to be included as a submodule for use in this project. 

![Unmodified. Owner: Alessandro Nassiri, License: https://creativecommons.org/licenses/by-sa/4.0/deed.en](https://github.com/lienwyatt/Enigma/assets/31666811/2764f0cb-efd2-4033-b092-6303df1ddd70)
Image credit: Alessandro Nassiri. Unmodified. Image License: https://creativecommons.org/licenses/by-sa/4.0/deed.en


