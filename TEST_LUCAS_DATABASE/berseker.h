#ifndef BERSEKER_H
#define BERSEKER_H
#include "personnage.h"

class berseker : public personnage
{
    protected:
    char* nom_du_perso;
    int nb_de_pt_de_vie;
    int pv=nb_de_pt_de_vie;
    int attaque;
    int defense;
    int energie;

    public:
    berseker();
    berseker(char*,int);
    void Frappe_punitive(personnage &cible);
    void Coup_dechaine(personnage &cible);
    void Movement_Alpha(personnage &cible);
    void bersekerpresentation();
};

#endif