#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>
#include <cstdlib>
using namespace std;


class personnage
{
    protected:
    char* nom_du_perso;
    int nb_de_pt_de_vie;
    int pv;
    int attaque;
    int defense;
    int energie;
    int vitesse;
    public:
    personnage();
    personnage(char*,int);
    void frappe_preventive(personnage &cible);
    void blast(personnage &cible);
    void attaque_delta(personnage &cible);
    void recevoir_dgts(int degat);
    int getVitesse();
    void presentation();
    void equiper(const string& nom_equipement);
};

#endif 