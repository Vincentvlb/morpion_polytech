#ifndef SPEECHRECOGNIZERCMD_HPP
#define SPEECHRECOGNIZERCMD_HPP

#include "mbed.h"
#include <map>

enum SpeechRecognizerCmd {DROITE=17, GAUCHE=16, HAUT=7, BAS=8, VALIDE=22};

class SpeechRecognizer
{
private:
    BufferedSerial pc;
    std::map<char, SpeechRecognizerCmd> traduction_usb_speechRecognizerCmd;
public:
    SpeechRecognizer(PinName usbTX, PinName usbRX);
    SpeechRecognizerCmd recuperation_commande();
};

#endif 