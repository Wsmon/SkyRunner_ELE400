/**
    Project : CableCam_Chariot\n
    @file SrEncodeur.h
    @brief Recupere la vitesse et distance lineaire

    @author Captnlink

    @version 1.0
    @date March 20, 2016

    @warning Il y a un delai(2000) (2s) dans le constructeur().
*/

#ifndef SRENCODEUR_H
#define SRENCODEUR_H

#include "LibEncoder.h"

#define SAMPLEVITESSE 10
#define RAYONCM 5

class SrEncodeur
{
    public:
        /** Default constructor */
        SrEncodeur();

        /** Update
         * @brief Mise a jour de la position et la vitesse selon les lectures de l'encodeur
         */
        void Update();

        /** Access PositionCm
         * @return The current value of PositionCm
         */
        int GetPositionCm() { return PositionCm; }

        /** Access Vitesse
         * @return The current value of Vitesse
         */
        int GetVitesse() { return VitesseMoy; }

    protected:

    private:
        Encoder EncodeurMecanique(2,3); //!< Objet "PositionCm"
        long mOldPosition;
        int mPositionCm; //!< Variable "PositionCm"
        int mVitesseMoy; //!< Variable "VitesseMoy" Vitesse Moyenne
        int mVitesseArray[SAMPLEVITESSE]; //!< Variable "VitesseArray" Vitesses pour la moyenne
};

#endif // SRENCODEUR_H
