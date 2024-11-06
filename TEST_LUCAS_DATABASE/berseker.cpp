#include "berseker.h"

 berseker::berseker():personnage(),nom_du_perso("Inconnu"),nb_de_pt_de_vie(200)
{

}

 berseker::berseker(char*prenom,int HP):personnage(),nom_du_perso(),nb_de_pt_de_vie()
{
    nom_du_perso=prenom;
    nb_de_pt_de_vie=HP;
    attaque = 10;
    defense = 5;
    energie = 0;
     vitesse = random() %9;
}


void berseker::Frappe_punitive(personnage &cible)
{
    cout << nom_du_perso << " effectue une frappe punitive \n"<<endl;
    cible.recevoir_dgts(0.30*nb_de_pt_de_vie);
    nb_de_pt_de_vie-=0.10*nb_de_pt_de_vie;
    energie+=20;


}

void berseker::Coup_dechaine(personnage &cible)
{
     cout<<nom_du_perso<<"effectue un coup déchainé\n"<<endl;
     cible.recevoir_dgts(0.50*nb_de_pt_de_vie);
     nb_de_pt_de_vie-=0.15*nb_de_pt_de_vie;
     energie+=30;
}

void berseker::Movement_Alpha(personnage &cible)
{
if (energie >= 100)
{
    cout << nom_du_perso << " effectue un Movement Alpha \n"<<endl;
    cible.recevoir_dgts(0.75*nb_de_pt_de_vie);
    nb_de_pt_de_vie+=0.50*nb_de_pt_de_vie;     
    energie -= 100;
}

else
    {
cout << nom_du_perso << " n'a pas assez d'énergie pour effectuer un Movement Alpha" << endl;
    }
}

void berseker::bersekerpresentation()
{
    cout<<"Mon nom est :"<<nom_du_perso<<"\n"<<endl;
    cout<<"Ma vitesse est :"<<vitesse<<"\n"<<endl;
    cout<<"Mon attaque est :"<<attaque<<"\n"<<endl;
    cout<<"Ma vie est :"<<nb_de_pt_de_vie<<"\n"<<endl;
    cout<<"Ma defense est :"<<defense<<"\n"<<endl;
}