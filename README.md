# Enigma Keyboard

## Description
This application allows the user to replicate the behavior of the Enigma machine on a Razer keyboard. When a key is pressed, the corresponding encrypted cyphertext letter lights up on the keyboard. A window launches where Enigma settings can be customized. The window can then be minimized and the encryption will continue to display on the keyboard while other applications are used. The application can still be run and used to perform Enigma encryption without a Razer keyboard. In that case the encryption will only be displayed to the terminal window and not also on the keyboard. 

## Background
The Enigma machine was a cipher device used to encode and decode German messages during WWII. The cipher was famously cracked by a team of codebreakers led by Alan Turing, helping the Allies to win WWII. For some good background on Enigma, check out [this video](https://www.youtube.com/watch?v=G2_Q9FoD-oQ). Because a pressed key never encrypts to itself in Enigma, you should always see a different key light up when one is pressed. 

## Instructions
The files needed to run the application without keyboard animations are contained in the 'Release' folder. That folder contains 64-bit and 32-bit executibles. To get the animations to dispay on the keyboard, you will also need to download [Razer Synapse 3](https://www.razer.com/synapse-3) and follow [these instructions](https://mysupport.razer.com/app/answers/detail/a_id/1758/~/how-to-use-chroma-connect) to make sure the Chroma Connect module is installed. 

https://github.com/lienwyatt/Enigma-Keyboard/assets/31666811/e23cc895-4dbc-4ba5-aca0-58f6c432f26a

## Method
Each key is registered as a hotkey to detect keypresses. This allows the keyboard to continue displaying the encrypted letters while using other applications. A different Chroma animation was created for each letter using the online [Chroma Editor](https://chroma.razer.com/ChromaEditor/). Swapping between these animations was done done with the official Razer Chroma C++ API and [sample app](https://github.com/razerofficial/CSDK_SampleApp). The sample app was forked as a submodule and adapted for use in this project. 

![Unmodified. Owner: Alessandro Nassiri, License: https://creativecommons.org/licenses/by-sa/4.0/deed.en](https://github.com/lienwyatt/Enigma/assets/31666811/2764f0cb-efd2-4033-b092-6303df1ddd70)
Image credit: Alessandro Nassiri. Unmodified. Image License: https://creativecommons.org/licenses/by-sa/4.0/deed.en


