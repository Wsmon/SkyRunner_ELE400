/*
  Xbee1
  The circuit: 
  * RX = pin 2 (connecter à TX de XBee)
  * TX = pin 3 (connecter à RX de XBee)
*/

#include <SoftwareSerial.h>


SoftwareSerial xbee(2, 3); // RX, TX
char msg[10] = {0,0,0,0,0,0,0,0,0,0};
int NbBit = 0;
int Connexion = 0;
int ManetteAdresse = 0;
// Variables pour la trame de contrôle
int Vitesse = 0;
int ArretUrgence = 0;
// Variables pour la trame de configuration
int Acceleration = 0;
int Deceleration = 0;
int LongueurCable[2] = {0,0};



void setup()  {
   Serial.begin(115200);
}

void loop() {
// Si Xbee a recu quelque

// Trame de demande de connexion: SOF = CXN
// msg[4] = tableau 1*4
// msg[0] = SOF[0]
// msg[1] = SOF[1]
// msg[2] = SOF[2]
// msg[3] = Adresse de la manette
// msg[4] = Checksum

while (Serial.available() > 0 && Connexion == 0 ) { 
  msg[NbBit]=Serial.read();
  
  // Trame de demande de connexion 
  if (NbBit==0){
    if (msg[0]== 'C'){                                                             // si la première lettre = C
      NbBit++;                                                                     // si oui, continuer
    }
    else{                                                                          // si non, recommencer
      NbBit=0;
      for (int i = 0; i = sizeof(msg); i++)                                        // effacer le tableau
        msg[i] = (char) 0;   
    }
  }
  if (NbBit==1){
    if (msg[1]== 'X'){                                                             // si la deuxième lettre = X
      NbBit++;                                                                     // si oui, continuer
    }
    else{                                                                          // si non, recommencer
      NbBit=0;
      for (int i = 0; i = sizeof(msg); i++)                                        // effacer le tableau
        msg[i] = (char) 0;   
    }
  }
  if (NbBit==2){
    if (msg[2]== 'N'){                                                             // si la troisième lettre = N
      NbBit++;                                                                     // si oui, continuer
    }
    else{                                                                          // si non, recommencer
      NbBit=0;
      for (int i = 0; i = sizeof(msg); i++)                                        // effacer le tableau
        msg[i] = (char) 0;
    }
  }
  if (NbBit==3){
    NbBit++;
  }
  if (NbBit==4){
    if (msg[4] == '4'){                                                            // si le contrôle a reçu toute la trame
      Connexion = 1;                                                               // si oui, connecter
      ManetteAdresse = msg[3];                                                     // prendre en note l'adresse de la manette connectée
    }
  NbBit=0;                                                                         // recommencer peu importe si on a reçu toute la trame au complête
  for (int i = 0; i = sizeof(msg); i++)                                            // effacer le tableau
    msg[i] = (char) 0;
  }  
}

while (Serial.available() > 0 && Connexion == 1 ) {
  msg[NbBit]=Serial.read();

  if (NbBit==0){
    if (msg[0]== 'C' || msg[0]== 'D'){                                             // si la première lettre = C ou D
      NbBit++;                                                                     // si oui, continuer
    }
    else{                                                                          // si non, recommencer
      NbBit=0;
      for (int i = 0; i = sizeof(msg); i++)                                        // effacer le tableau
        msg[i] = (char) 0;   
    }
  }
  if (NbBit==1){
    if (msg[0]== 'C' && msg[1]== 'N'){                                             // si les deux premières lettres = C et N
      NbBit++;                                                                     // si oui, continuer
    }
    else if (msg[0]== 'D' && msg[1]== 'C'){                                        // si les deux premières lettres = D et C               
      NbBit++;                                                                     // si oui, continuer
    }
    else{                                                                          // si non, recommencer
      NbBit=0;
      for (int i = 0; i = sizeof(msg); i++)                                        // effacer le tableau
        msg[i] = (char) 0;
    }
  }
  if (NbBit==2){
    if (msg[0]== 'C' && msg[1]== 'N' && msg[2]== 'T'){                             // si les trois premières lettres = C, N et T (Trame de contrôle)              
      NbBit++;                                                                     // si oui, continuer
    }
    else if (msg[0]== 'C' && msg[1]== 'N' && msg[2]== 'F'){                        // si les trois premières lettres = C, N et F (Trame de configuration)                   
      NbBit++;                                                                     // si oui, continuer
    }
    else if (msg[0]== 'D' && msg[1]== 'C' && msg[2]== 'X'){                        // si les trois premières lettres = D, C et X (Trame de demande de déconnexion)                              
      NbBit++;                                                                     // si oui, continuer
    }
    else{                                                                          // si non, recommencer
      NbBit=0;
      for (int i = 0; i = sizeof(msg); i++)                                        // effacer le tableau
        msg[i] = (char) 0;
    }
  }
  if (NbBit==3 && ManetteAdresse == msg[3]){                                       // si la trame est envoyé par la manette qu'on a connectée
    NbBit++;                                                                       // si oui, continuer
  }
  else{                                                                            // si non, recommencer
    NbBit=0;
    for (int i = 0; i = sizeof(msg); i++)                                          // effacer le tableau
      msg[i] = (char) 0;
  }
  if (NbBit==4){                                                                   
    if (msg[0]== 'D' && msg[1]== 'C' && msg[2]== 'X'){                             // Pour la trame de demande de déconnexion
      if (msg[4] == '4'){                                                          // si le contrôle a reçu toute la trame
        Connexion = 0;                                                             // si oui, déconnecter
      }
    NbBit=0;                                                                       // recommencer peu importe si on a reçu toute la trame au complête
    for (int i = 0; i = sizeof(msg); i++)                                          // effacer le tableau
      msg[i] = (char) 0;
    }
    else{                                                                          // si la trame reçue n'est pas la trame de demande de déconnexion, continuer
      NbBit++;
    } 
  }
  if (NbBit==5){
    NbBit++;
  }
  if (NbBit==6){                                                                   
    if (msg[0]== 'C' && msg[1]== 'N' && msg[2]== 'T'){                             // Pour la trame de contrôle
      if (msg[6] == '6'){                                                          // si le contrôle a reçu toute la trame
        Vitesse = msg[4];                                                          // si oui, prendre en note la vitesse demandée
        ArretUrgence = msg[5];                                                     // prendre en note si l'arrêt d'urgence est demandé
      }
    NbBit = 0;                                                                     // recommencer peu importe si on a reçu toute la trame au complête
    for (int i = 0; i = sizeof(msg); i++)                                          // effacer le tableau
      msg[i] = (char) 0;  
    }
    else{                                                                          // si la trame reçue n'est pas la trame de contrôle, continuer
      NbBit++;
    }
  }
  if (NbBit==7){
    NbBit++;
  }
  if (NbBit==8){                                                                   
    if (msg[0]== 'C' && msg[1]== 'N' && msg[2]== 'F' && msg[8] == '8'){            // Pour la trame de configuration, si le contrôle a reçu toute la trame
      Acceleration = msg[4];                                                       // si oui, prendre en note l'accélération requise
      Deceleration = msg[5];                                                       // prendre en note la décélération requise
      LongueurCable[0] = msg[6];                                                   // prendre en note la longueur du câble utilisé
      LongueurCable[1] = msg[7];      
    }  
    else{
      NbBit = 0;                                                                   // recommencer peu importe si on a reçu toute la trame au complête
      for (int i = 0; i = sizeof(msg); i++)                                        // effacer le tableau
        msg[i] = (char) 0;
    }
  }
}
}
