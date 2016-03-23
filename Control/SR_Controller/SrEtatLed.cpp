EtatLed::EtatLed(){
	ledActualState = 0; //État de la LED (Allumé ou éteinte)
	controllerState = 0; //État du controlleur
}

bool EtatLed:UpdateLedState(/*State of Controler*/){
	return false;
}