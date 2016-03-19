#include "GameLoop.h"

//Includes
//Include default configuration

Controller::Controller()
{
    dState; 
	iState; 
	iMax = 0;
	iMin = 10;
	iGain = 0;
	pGain = 1;
	dGain = 0;
}

double Controller::Update(double error, double speed){
	double pTerm, dTerm, iTerm;
	
	//Proportional term
	pTerm = pGain * error;
	
	//Intergral term
	iState += error;	
	if(iState > iMax) iState = iMax;
	else if(iState < iMin) iState = iMin;
	iTerm = iGain * iState;
	
	//Derivate term
	dTerm = dGain * (dState - speed);
	dState = speed;
	
	return pTerm + dTerm + iTerm;	
	
}