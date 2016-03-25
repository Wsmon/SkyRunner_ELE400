BrainControl::BrainControl(){

	mPositionActuel=0; //Position du chariot sur le cable
	mPositionMax=0; //Position maximum du point de départ (Longueur de cable)

	mVitesseActuel=0;
	mVitesseVoulu=0;

	mDistanceAvant = 0;  //Distance vue par le capteur de distance avant
	mDistanceArriere = 0;//Distance vue par le capteur de distance arriere

	mOutputPID = 0; //Output fournit a la drive, controller par le PID
	mAcceleration=0;  // 0 = Max et 5 = Very Slow

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
    //mDistanceAvant = GetDistanceCapteurAvant();
    //mDistanceArriere = GetDistanceCapteurArriere();
    SetVitesseVoulu(mVitesseVoulu);

    mOutputPID = PID.UpdatePid(mVitesseVoulu - mVitesseActuel,mVitesseActuel);
    if(mOutputPID>127)mOutputPID =127; //Max output qui peut etre fournit a la drive
    if(mOutputPID<-127)mOutputPID =-127;//Max output qui peut etre fournit a la drive

    if(mAcceleration == 0) SyrenDrive.setRamping(1);
    else if(mAcceleration == 1) SyrenDrive.setRamping(10);
    else if(mAcceleration == 2) SyrenDrive.setRamping(25);
    else if(mAcceleration == 3) SyrenDrive.setRamping(80);
    else if(mAcceleration == 4) SyrenDrive.setRamping(11);
    else SyrenDrive.setRamping(20);

    SyrenDrive.motor(mOutputPID);
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


bool BrainControl::SetAcceleration(int _acceleration){
    if(_acceleration == 0) mAcceleration = 0;
    else if(_acceleration == 1) mAcceleration = 1;
    else if(_acceleration == 2) mAcceleration = 2;
    else if(_acceleration == 3) mAcceleration = 3;
    else if(_acceleration == 4) mAcceleration = 4;
    else return false;
    return true;
}


bool BrainControl::CalculPosition(/*State of Controler*/){
	return 0;
}
