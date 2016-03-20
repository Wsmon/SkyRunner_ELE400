/*Créateur:Wantel Simon 
Description:Cette librairie permet déterminer la température et la tension de la batterie
*/

#ifndef (OK_BATTERIE) // pour empecher la double-compilation 
#define OK_BATTERIE 


/*
#DEFINE PIN_THERMISTANCE 
#DEFINE PIN_DIVISEUR_TENSION

//valeur pour le calcul de la température 
#DEFINE THERMISTANC_TEMP-_AMB 10000 // resistance a la température de la salle
#DEFINE TEMPERATURE_AMBIANTE 25 // température de la salle
#DEFINE NB_SAMPLES  // nombre d'échantillons pour faire le calcul
#DEFINE BCOEFFICIENT // le coefficient beta du thermisor (généralement entre 3000-4000)
#DEFINE RÉSISTANCE  //valeur de la résistance avec la thermistance
*/

/* get_temp permet de déterminer la température de la batterie à partir de la tension au 
borne de la thermistance.
Paramètre d'entrée: l'adresse du numéro de la pin a lire et la tension 
Donnée Retour de la fonction:
*/

// void get_temp(int* batterie_temp,int pin_thermistance);

 

/* get_tension permet de lire la tension de la batterie .
Paramètre d'entrée: l'adresse des données batteries
Donnée Retour de la fonction:
*/

// void get_tension(int* batterie_tension, int pin_diviseur_tension);


#endif
