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

#include "SrEncodeur.h"
#include "SrThermistance.h"
#include "PidController.h"

#define MAX_POSITION_LV_4 400 //En cm
#define MAX_POSITION_LV_3 300 //En cm
#define MAX_POSITION_LV_2 200 //En cm
#define MAX_POSITION_LV_1 100 //En cm


/**
    @class BrainControl BrainControl.h
    @brief Gere la securite automatique et le controle de la drive

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

	int mPositionChariotActuel;
	int mPositionChariotVoulu;
	int mPositionActuel; //Position du chariot sur le cable (cm)
	int mPositionMax; //Position maximum du point de départ (Longueur de cable) (cm)
	int mVitesseActuel; // en cm/sec
	int mVitesseVoulu;// en cm/sec
    int mDistanceAvant;  //Distance vue par le capteur de distance avant
	int mDistanceArriere;//Distance vue par le capteur de distance arriere


    //100 = Vitesse Max avant
    //50  = Vitesse Null
    //0   = Vitesse Max arriere
	double mOutputPID;

	//Accel/Decel (0 a 5)
	int mAcceleration; // 0 = None et 5 = Max
	int mDecceleration; // 0 = Max et 5 = Min

	bool arretUrgence;

	PidController PID;
	SrEncodeur Encodeur;
    Thermistance TempBatterie;

public:
    BrainControl();

    void Update();

    bool SetArretUrgenge();
    bool IsArretUrgence(return arretUrgence);

	//Setters
	void SetVitesseVoulu();
	void SetPositionMax();

	void SetAcceleration();
	void SetDeceleration();

	//Getters
	int GetVitesseVoulu(return mVitesseVoulu);
	int GetVitesseActuel(return mVitesseActuel);

	int GetPositionMax(return mPositionMax);
	int GetPositionActuel(return mPositionActuel);

	int GetAcceleration(return mAcceleration);
	int GetDeceleration(return mDecceleration);

	double GetTemperatureBaterie(return TempBatterie.GetTempratureCelsius());

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
