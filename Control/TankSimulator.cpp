/** \mainpage Tank Simulator
 *
 * \section intro Introduction
 *
 * This project take a simulated tank and control the level with a PID controller
 *
 */


#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Controller.h"

using namespace std;

#define NIVEAU_MAX 100
#define NIVEAU_MIN 0

void printReservoir(double niveau)
{
    system("cls");
    printf("NiveauReservoir : %f\n",niveau);
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    /*
        for(int i = NIVEAU_MAX; i > NIVEAU_MIN; i--)
        {
            printf("|");
            if(niveau >= i)printf("~~~~~");
            else printf("     ");
            printf("|");
            if(i == NIVEAU_MAX){printf("%f",niveau);}
            printf("\n");
        }
        printf("\n");
        for(int i=0; i<100;i++){}*/
}

double UpdateReservoir(double niveau, double pourcentValve, double percentPompe)
{
    //Simulate de level of water in a tank

    //updateNiveau est le debit d'eau entrant dans le reservoir
    double updateNiveau =0;
    updateNiveau  = 2*percentPompe/100;
    updateNiveau -= 2*(100-pourcentValve)/100;
    updateNiveau -= niveau/100;

    //if(updateNiveau < 0) updateNiveau = 0;

    niveau += updateNiveau;

    if(niveau > NIVEAU_MAX) niveau = NIVEAU_MAX;
    if(niveau < NIVEAU_MIN) niveau = NIVEAU_MIN ;


    return niveau;
}

void printGraph(int* graph, double niveau, int time)
{
    int graphNiveau = niveau;
    graphNiveau /= 5;


    graph[time%50] = graphNiveau;
    for(int y = 20; y > 0; y--)
    {
        printf("|");
        for(int x = 0; x < 50; x++)
        {
            if(graph[x]==y) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    printf("________________________________________________________");
}

int main()
{
    cout << "Hello world!" << endl;

    int i,j = 0;
    double niveauActuel = 0;
    double valveOpening = 0;
    double consigne = 60;
    PidController PID;
    PID.setpGain(10);
    PID.setiGain(0.1);

    //Init Graph
    int graph[50];
    for(int y = 0; y < 50; y++)
    {
            graph[y] = 0;
    }

    cout << "To quit the simulation, press CTRL+C" << endl;
    system("PAUSE");

    while(true)
    {
        i++;
        valveOpening = PID.UpdatePid(consigne - niveauActuel,niveauActuel);
        if(valveOpening>100)valveOpening=100;
        else if(valveOpening<0)valveOpening=0;
        if(!(i%5))
        {
            j++;
            niveauActuel = UpdateReservoir(niveauActuel,valveOpening, 100);
            printReservoir(niveauActuel);
            printf("Error : %f\n",consigne - niveauActuel);
            printf("Valve : %f\n",valveOpening);
            printGraph(graph, niveauActuel, j);
        }







    }



    return 0;
}
