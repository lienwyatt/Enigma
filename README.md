# Enigma Keyboard

## Description
This application allows the user to replicate the behavior of the WWII Enigma machine on a Razer keyboard. When a key is pressed, the corresponding encrypted cyphertext letter lights up on the keyboard. A window launches where Enigma settings can be customized. The window can then be minimized and the encryption will continue to display on the keyboard while other applications are used. The application can still be run and used to perform Enigma encryption without a Razer keyboard. In that case the encryption will only be displayed to the terminal window and not also on the keyboard. 

## Background
The Enigma machine was a cipher device used to encode and decode German messages during WWII. The cipher was famously cracked by a team of codebreakers led by Alan Turing, helping the Allies to win WWII. For some good background on Enigma, check out [this video](https://www.youtube.com/watch?v=G2_Q9FoD-oQ).

## Demonstrations

[![Keyboard Demo](https://github.com/lienwyatt/Enigma-Keyboard/assets/31666811/2f66a08c-2e08-463f-9172-255f7b480b57)](https://youtu.be/S3wwKLhFq8w)


[![Decryption Example](https://github.com/lienwyatt/Enigma-Keyboard/assets/31666811/ccaaa3a3-f922-4f39-9044-3a5b2cb99743)](https://www.youtube.com/watch?v=jrvAljH7J1c)

## Instructions
The files needed to run the application are contained in the 'Release' folder. That folder contains Windows 64-bit and 32-bit executables. To also get the animations to display on a Razer keyboard, you will need to download [Razer Synapse 3](https://www.razer.com/synapse-3) and follow [these instructions](https://mysupport.razer.com/app/answers/detail/a_id/1758/~/how-to-use-chroma-connect) to make sure the Chroma Connect module is installed. A Razer keyboard is not needed to perform encryption with the console application. 

## Method
Each key is registered as a hotkey to detect keypresses. This allows the keyboard to continue displaying the encrypted letters while using other applications. A different Chroma animation was created for each letter using the online [Chroma Editor](https://chroma.razer.com/ChromaEditor/). Swapping between these animations was done done with the official Razer Chroma C++ API and [sample app](https://github.com/razerofficial/CSDK_SampleApp). The sample app was forked as a submodule and adapted for use in this project. 

## References
Sample messages for decryption can be found here: \
http://wiki.franklinheath.co.uk/index.php/Enigma/Sample_Messages \
Details of Enigma design were taken from here: \
https://www.ciphermachinesandcryptology.com/en/enigmatech.htm \
https://en.wikipedia.org/wiki/Enigma_rotor_details \
https://en.wikipedia.org/wiki/Enigma_machine


