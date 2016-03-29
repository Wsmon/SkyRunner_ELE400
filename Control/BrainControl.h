/**
    Project : CableCam_Chariot\n
    @file BrainControl.h
    @brief Gère le contrôle du moteur selon les interfaces externes

    @author Captnlink
	
    @version 1.0
    @date March 20, 2016

	Gère le moteur avec un PID et les informations receuillit par les capteurs (autres classes)
	
*/

#ifndef BRAINCONTROL_H_
#define BRAINCONTROL_H_


/**
    @class BrainControl BrainControl.h
    @brief gère l'état de la LED d'information

    @author Captnlink
    @version 1.1
    @date March 20, 2016

    Gère le PID du controle de vitesse. Process les informations des capteurs et de l'interfaces
	afin d'envoyer à la drive une consigne en tension.
	
*/
class BrainControl
{
private:
    //Mettre dans le .h des default config, un enum pour chaque possibilité d'erreur
	
	int directionChariotActuel; 
	int directionChariotVoulu; 
	double distance; //Distance du chariot sur le cable
	double distanceMax; //Distance maximum du point de départ (Longueur de cable)
	double vitesseActuel;
	double vitesseVoulu;
	
	//Accel/Decel (0 a 5) 
	int acceleration; // 0 = None et 5 = Max
	int decceleration; // 0 = Max et 5 = None
	
public:
    BrainControl();

	
	//Setters
	void SetVitesseVoulu();
	void SetDistanceMax

	//Getters

private:
    /**
    @fn CalculPosition
    @brief Fait le calcul de position selon la direction et les pulses par revolution
    @param [NAME] : Paramètre de la founction
    @return double en mètres

    */
	double CalculPosition(/*directionChariotActuel + directionChariotVoulu*/);
	
}

#endif