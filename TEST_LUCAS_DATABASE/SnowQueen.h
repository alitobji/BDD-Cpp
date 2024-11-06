#ifndef SNOWQUEEN_H
#define SNOWQUEEN_H
#include "berseker.h"

class SnowQueen : public personnage
{
    protected:
    char* nom_du_perso;
    int nb_de_pt_de_vie;
    int pv=nb_de_pt_de_vie;
    int attaque;
    int defense;
    int energie;

    public:
    SnowQueen();
    SnowQueen(char*,int);
    void Javelot_de_glace(personnage &cible);
    void Vent_glaciale(personnage &cible);
    void Let_It_Go(personnage &cible);
      void SnowQueenpresentation();
};
#endif