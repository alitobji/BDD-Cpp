
#include "berseker.h"
#include "SnowQueen.h"

int main()
{
personnage Ouledi("Ouledi",50);
berseker Ghost("Ghost",500);
SnowQueen Price("Price",300);

Ouledi.presentation();
Ghost.bersekerpresentation();
Price.SnowQueenpresentation();
cout<<"//////////////////////////////////::"<<endl;
Ouledi.equiper("Casque");
Ouledi.equiper("botte");
Ouledi.equiper("heaume");
Ouledi.equiper("gants");
Ouledi.presentation();
return 0;
}




















/*while(Ouledi().getVitesse()>Ghost().getVitesse() && Ouledi().getVitesse()>Price().getVitesse())
{
    int choix;
    cin>>choix;
    cout<<"1- ATTAQUE FRAPPE PREVENTIVE\n"<<endl;
    cout<<"2- ATTAQUE BLAST\n"<<endl;
    cout<<"3- ATTAQUE DELTA\n"<<endl;
switch (choix) {

    
            case 1: 
            { 
                Ouledi().frappe_preventive(Ghost);
                break;
            }
            case 2: 
            {
                Ouledi().blast(Ghost);
               break;
            }
             case 3: 
            {
                Ouledi().attaque_delta(Ghost);
                break;
            }
            
}
}while (choix != 0);
else if (Ghost().getVitesse()>Ouledi().getVitesse() && Ghost().getVitesse()>Price().getVitesse())
{
int choix;
    cin>>choix;
    cout<<"1- ATTAQUE FRAPPE PUNITIVE\n"<<endl;
    cout<<"2- ATTAQUE COUP DECHAINE\n"<<endl;
    cout<<"3- ATTAQUE MOVEMENT ALPHA\n"<<endl;
switch (choix) {

    
            case 1: 
            { 
                Ghost().Frappe_punitive();
                break;
            }
            case 2: 
            {
                Ouledi().Coup_dechaine();
               break;
            }
             case 3: 
            {
                Ouledi().Movement_Alpha();
                break;
            }
}
}while (choix!=0);
else if(Price().getVitesse()>Ouledi().getVitesse() && Price().getVitesse()>Ghost().getVitesse())
{
    int choix;
    cin>>choix;
    cout<<"1- ATTAQUE JAVELOT DE GLACE\n"<<endl;
    cout<<"2- ATTAQUE VENT GLACIALE\n"<<endl;
    cout<<"3- ATTAQUE LET IT GO \n"<<endl;
switch (choix) {

    
            case 1: 
            { 
                Ghost().Javelot_de_glace();
                break;
            }
            case 2: 
            {
                Price().Vent_glaciale();
               break;
            }
             case 3: 
            {
                Price().Let_It_Go();
                break;
            }
}
}while (choix!=0);*/


/*
}
*/