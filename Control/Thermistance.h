/**
    Project : CableCam_Chariot\n
    @file Thermistance.h
    @brief R�cup�re la temp�rature de la thermistance

    @author Captnlink
	
    @version 1.0
    @date March 20, 2016
	
*/

#ifndef THERMISTANCE_H_
#define THERMISTANCE_H_

#include <Arduino.h>

// which analog pin to connect
#define THERMISTORPIN A0         
// resistance at 25 degrees C
#define THERMISTORNOMINAL 10000      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25   
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 10000    


/*
  //Put in the setup of the main

 */

 /**
    @class Thermistance Thermistance.h
    @brief Permet l'acquisition d'une valeur de temperature

    @author Captnlink
	@author Lady Ada
	
    @version 1.1
    @date March 20, 2016


*/
class Thermistance
{
private:

	int i;
	double average;
	int samples[NUMSAMPLES];
	double steinhart;
	
	void GetSample();
	void ConvertAnalogueToResistance();
	void ConvertResistanceToCelcius();
	
public:
    Thermistance();
	
    /**
    @fn GetTempratureCelsius
    @brief R�cup�re la temp�rature en �C
    @return double Temperature �C
    */
	double GetTempratureCelsius();

};

#endif
