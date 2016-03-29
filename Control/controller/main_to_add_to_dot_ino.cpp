/**
    Project : CableCam_Chariot\n
    @file main.c
    @brief Gèrent la répartition des données entre les différents modules 

    @author Captnlink
	@author Wsimon
	
    @version 1.0
    @date March 20, 2016

	Lorsque le controlleur démarre, il donne les configurations par default.
	Fait la gestion des tram de communication entrant/sortant.
	Contient la routine de contrôle.
	
*/


/**
	@fn changementConfig
	@brief vérifie s'il y a un changement de configurations reçu de l'interface
	@Param [Name1] Trame de communication reçu
	@return bool true = changement, false = Aucun changement
	
	Permettant de vérifier les différences entre la trame reçu de l'interface 
	et la configuration actuel du contrôleur. 
	S'il a des différences, on apporte  les modifications nécessaires 

*/
bool changementConfig(){
	
	return false;
}

/**
	@fn etatLed
	@brief Envoie l'information du  controller à l'interface LED
	@Param [Name1] Information controlleur
	@return char binaire des erreurs
	
	La Led affiche un code de couleur et de flash pour indiquer
	les codes d'erreurs

*/
bool etatLed(){
	
	return false;
}