#include "SpeechRecognizerCmd.hpp"

SpeechRecognizer::SpeechRecognizer(PinName usbTX, PinName usbRX): pc(usbTX,usbRX){
    traduction_usb_speechRecognizerCmd = {
        {'d', SpeechRecognizerCmd::DROITE}, 
        {'g', SpeechRecognizerCmd::GAUCHE}, 
        {'h', SpeechRecognizerCmd::HAUT}, 
        {'b', SpeechRecognizerCmd::BAS}, 
        {'v', SpeechRecognizerCmd::VALIDE}
    };
}

SpeechRecognizerCmd SpeechRecognizer::recuperation_commande(){
    while(1){
        printf("Attente d'un commande ...\r\n");
        char buff;
        pc.read(&buff, 1);
        if(traduction_usb_speechRecognizerCmd.count(buff)){
            return traduction_usb_speechRecognizerCmd[buff];
        }else{
            printf("La commande : '%c' n'existe pas !\n", buff);
        }
    }
}
