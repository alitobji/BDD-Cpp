
#include "SnowQueen.h"

 SnowQueen::SnowQueen():personnage(),nom_du_perso("Inconnu"),nb_de_pt_de_vie(200)
{

}

 SnowQueen::SnowQueen(char*pseudo,int vivance):personnage(),nom_du_perso(),nb_de_pt_de_vie()
{
    nom_du_perso=pseudo;
    nb_de_pt_de_vie=vivance;
    attaque = 10;
    defense = 5;
    energie = 0;
     vitesse = random() %9;
}


void SnowQueen::Javelot_de_glace(personnage &cible)
{
    cout << nom_du_perso << " Lance un javelot de glace\n"<<endl;
    cible.recevoir_dgts(10*1.25);
    energie+=20;
}

void SnowQueen::Vent_glaciale(personnage &cible)
{
     cout<<nom_du_perso<<"Frappe avec un Vent glacial\n"<<endl;
     cible.recevoir_dgts(10*1.50);
     energie+=30;
}

void SnowQueen::Let_It_Go(personnage &cible)
{
if (energie >= 100)
{
    cout<<nom_du_perso<<"Utilise sa capacité Let it go\n"<<endl;
   cible.recevoir_dgts(10*1.75);
   energie-=100;
}

else
    {
cout << nom_du_perso << " n'a pas assez d'énergie pour effectuer un Movement Alpha" << endl;
    }
}
void SnowQueen::SnowQueenpresentation()
{
    cout<<"Mon nom est :"<<nom_du_perso<<"\n"<<endl;
    cout<<"Ma vitesse est :"<<vitesse<<"\n"<<endl;
    cout<<"Mon attaque est :"<<attaque<<"\n"<<endl;
    cout<<"Ma vie est :"<<nb_de_pt_de_vie<<"\n"<<endl;
    cout<<"Ma defense est :"<<defense<<"\n"<<endl;
}