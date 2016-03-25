BrainControl::BrainControl(){
    mPositionChariotActuel=0;
	mPositionChariotVoulu=0;
	mPositionActuel=0; //Position du chariot sur le cable
	mPositionMax=0; //Position maximum du point de départ (Longueur de cable)
	mVitesseActuel=0;
	mVitesseVoulu=0;
	mDistanceAvant = 0;  //Distance vue par le capteur de distance avant
	mDistanceArriere = 0;//Distance vue par le capteur de distance arriere

	mOutputPID = 0;

	//Accel/Decel (0 a 5)
	mAcceleration=0; // 0 = None et 5 = Max
	mDecceleration=0; // 0 = Max et 5 = None
	arretUrgence = true;
}

bool BrainControl::SetArretUrgenge(){
    arretUrgence = true;
    return arretUrgence;
}

void BrainControl::Update(){
    Encodeur.Update();
    mVitesseActuel = Encodeur.GetVitesse();
    mPositionActuel = Encodeur.GetPositionCm();
    SetVitesseVoulu(mVitesseVoulu);


    //100 = Vitesse Max avant
    //0  = Vitesse Null
    //-100   = Vitesse Max arriere
    mOutputPID = PID.UpdatePid(mVitesseVoulu - mVitesseActuel,mVitesseActuel);
    if(mOutputPID>100)mOutputPID =100;
    if(mOutputPID<-100)mOutputPID =-100;
}

//_vitessevoulu en cm/sec
void BrainControl::SetVitesseVoulu(int _vitesseVoulu)
{
    if(!arretUrgence)
    {
        if(mVitesseActuel > 0)
        {
            if((mPositionActuel < (mPositionMax - MAX_POSITION_LV_4))|| (mDistanceAvant > 4 && mDistanceAvant < 5) ) //Si le bolide arrive a 4m de la fin OU un objet
            {
                if(_vitesse > 5) _vitesse =0 TOP4;/*Set Vitesse top*/
                else mVitesseVoulu = _vitesseVoulu; /*Set vitesse _vitesse */
            }
        }
        //Repeat for mVitesseActuel < 0

    }
    else _vitesse = 0;
}
void BrainControl::SetPositionMax();

//Set le gain P du systeme et l'output max
void BrainControl::SetAcceleration();
void BrainControl::SetDeceleration();

bool BrainControl::CalculPosition(/*State of Controler*/){
	return 0;
}
