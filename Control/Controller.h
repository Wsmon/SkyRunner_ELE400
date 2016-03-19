#ifndef Controller_H_
    #define Controller_H_

	/*
 *Name 			: controller 
 *Project 		: CableCam_Chariot
 *Description 	: 
 *		PID control
 *		
 *Created by 	: Samuel Geoffroy AKA Captnlink, March 19, 2016.
 *Last Modif	: March 19, 2016.
 *Released into the public domain.
*/

//Includes

//Defines


class Controller{
    private:
        double  dState; //Last position
		double  iState; //Integrator state
		double  iMax,iMin //MAx and min allowable integrator state
		
		//PID Gain
		double  iGain,
				pGain,
				dGain;

    public:
        Controller();
        double Update(double error, double speed);
};

#endif