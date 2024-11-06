
#include"personnage.h"

personnage::personnage():nom_du_perso("Inconu"),nb_de_pt_de_vie(100)
{

}


personnage::personnage(char* blaze,int vie)
{
    nom_du_perso = blaze;
    nb_de_pt_de_vie = vie;
    attaque = 10;
    defense = 5;
    energie = 0;
    vitesse = random() %9;
}


void personnage::recevoir_dgts(int degat) 
{
    cout<<defense<<endl;
    cout<<nom_du_perso<<"  a recu des degat\n"<<endl;
    if (defense==0)
    {
        nb_de_pt_de_vie-=degat;
    }
    else if(defense>0)
    {
        degat-=defense;
        nb_de_pt_de_vie-=degat;
        defense-=degat;
        if (defense<0)
        {
            defense=0;
        }
    }
    cout<<nom_du_perso<<":"<<nb_de_pt_de_vie<<" PV\n"<<endl; 

    if (nb_de_pt_de_vie<0)
    {   
    nb_de_pt_de_vie = 0;
    cout<<nom_du_perso<<"  PERSONNAGE EST MORT"<<endl; 
    }

}
void personnage::frappe_preventive(personnage &cible)
{

cout<<nom_du_perso<<"  utilise une frappe preventive \n"<<endl;
cible.recevoir_dgts(10);
energie += 10;
}

void personnage::blast(personnage &cible)
{
cout<<nom_du_perso<<" inflige un blast  \n"<<endl;
cible.recevoir_dgts(15);
energie +=15;
}


void personnage::attaque_delta(personnage &cible)
{
if (energie >= 100)
{
    cout << nom_du_perso << " effectue une attaque Delta \n"<<endl;
    cible.recevoir_dgts(35);     
    energie -= 100;
}

else
    {
cout << nom_du_perso << " n'a pas assez d'énergie pour effectuer une attaque Delta." << endl;
    }
}

int personnage::getVitesse()
{
    return vitesse;
}

void personnage::presentation()
{
    cout<<"Mon nom est :"<<nom_du_perso<<"\n"<<endl;
    cout<<"Ma vitesse est :"<<vitesse<<"\n"<<endl;
    cout<<"Mon attaque est :"<<attaque<<"\n"<<endl;
    cout<<"Ma vie est :"<<nb_de_pt_de_vie<<"\n"<<endl;
    cout<<"Ma defense est :"<<defense<<"\n"<<endl;
}

void personnage::equiper(const string& nom_equipement)
{
    cout << endl;
cout << "Premier test du connecteur C++ Mysql" << endl;
 
// La gestion d'erreur se fait proprement avec les exceptions
// sinon retirer le try...catch
 
try {
  // Les variables nécessaires à notre programme
  sql::Driver* driver;
  sql::Connection* con;
  sql::Statement* stmt;
  sql::ResultSet* res;
 
  // Etape 1 : créer une connexion à la BDD
  driver = get_driver_instance();
  // on note les paramètres classiques: adresse ip du serveur et port, login, mot de passe
  con = driver->connect("localhost", "student", "crif2024sn");
 
  // Etape 2 : connexion à la base choisie, ici olivier_db
  con->setSchema("equipementsLucas");
 
  // Etape 3 : création d'un objet qui permet d'effectuer des requêtes sur la base
  stmt = con->createStatement();
 
  // Etape 4 : exécution d'une requete : ici on sélectionne tous les enregistrements
  // de la table Animal
  res = stmt->executeQuery("SELECT * FROM bonus WHERE nom='" + nom_equipement + "'");

  
  // Etape 5 : exploitation du résultat de la requête
  if (res->next()) {
    // Acces à la donnée par son numéro de colonne, 1 étant le premier (ici 'id'), 5 le nom de l'animal
    cout << res->getString("nom") << endl;
    cout << "Bonus de vie: "<<res->getString("vie") << endl;
    cout << "Bonus d'attaque: "<<res->getString("attaque") << endl;
    cout << "Bonus de vitesse: "<<res->getString("vitesse") << endl;
    cout << "Bonus de defense: "<<res->getString("defense") << endl;
    cout <<"\n"<<endl;
    int vie_cosmetique = stoi(res->getString("vie"));
    int attaque_cosmetique = stoi(res->getString("attaque"));
    int vitesse_cosmetique = stoi(res->getString("vitesse"));
    int defense_cosmetique = stoi(res->getString("defense"));
    nb_de_pt_de_vie+=vie_cosmetique;
    attaque+=attaque_cosmetique;
    vitesse+=vitesse_cosmetique;
    defense+=defense_cosmetique;
    cout<<"le personnage c'est equiper du cosmetique"<<endl;
  }else {
    cout<<"le cosmetique est introuvable dans la BDD"<<endl;
  }
 
  // On nettoie tout avant de sortir : effacement des pointeurs
  // le pointeur sur le Driver sera effacé tout seul
  delete res;
  delete stmt;
  delete con;
 
} catch (sql::SQLException &e) {
  // Gestion des execeptions pour déboggage
  cout << "# ERR: " << e.what();
  cout << " (code erreur MySQL: " << e.getErrorCode();
  cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
 
cout << endl;
 

}




