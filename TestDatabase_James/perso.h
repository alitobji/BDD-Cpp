#include <iostream>     // Inclure la bibliotheque iostream
using namespace std;    // Inclure bibliotheque std pour permettre de mettre std:: dans chaque fonction de cout 
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <random>


class Perso             // Creation de la class Perso 
{
    protected:          // Permet a utiliser dehors de sa class 
    char *nom_du_perso; // Declaration des attribut de la class Perso
    int nb_de_pt_de_vie;
    int attaque;
    int defence;
    int vitesse;
    int energie;

    public:             // Creation des Constructeur et des methodes    
    Perso(char *, int); // Declaration du constructeur avec 2 parametres de l'attribut nom_de_perso et nb_de_pt_de_vie
    void frappe_preventive(Perso &cible); // Declaration de methode cp_de_pg avac la reference
    void Blast(Perso &cible);
    void Attaque_Delta(Perso &cible);
    int EquipHelmet();
    char *getName();
    int getHealth();
};