#include "perso.h"

Perso::Perso(char *nom, int vie)     // Definition du constructeur perso avec 2 parametres
{
    nom_du_perso = nom;              // Affectation des valeur a les attributs
    nb_de_pt_de_vie = vie;
    attaque = 40;
    defence = 20;
    vitesse = 9;    
    energie = 0;
}

char *Perso::getName()
{
    return nom_du_perso;
}

int Perso::getHealth()
{
    return nb_de_pt_de_vie;
}

void Perso::frappe_preventive(Perso& cible)    // Definition de methode avec reference 
{
    cout << endl << nom_du_perso << " used Preemptive Strike!! and received 10 energy." << endl;
    energie += 10;
    cible.nb_de_pt_de_vie -= attaque;
    cout << endl << cible.nom_du_perso << " received " << attaque << " damage." << endl;
    cout << endl << cible.nom_du_perso << " Health: " << cible.nb_de_pt_de_vie << endl;
}

void Perso::Blast(Perso &cible)
{
    cout << nom_du_perso << " used Blast!! and received 15 energy." << endl;
    energie += 15;
    attaque *= 1.5;
    cible.nb_de_pt_de_vie -= attaque;
    cout << endl << cible.nom_du_perso << " received " << attaque << " damage." << endl;
    cout << endl << cible.nom_du_perso << " Health: " << cible.nb_de_pt_de_vie << endl;
}

void Perso::Attaque_Delta(Perso &cible)
{
    cout << nom_du_perso << " used Delta Attack." << endl;
    if(energie == 100)
    {
        energie -= 100;
        attaque *= 3.5;
        cible.nb_de_pt_de_vie -= attaque;
        cout << endl << cible.nom_du_perso << " received " << attaque << " damage." << endl;
        cout << endl << cible.nom_du_perso << " Health: " << cible.nb_de_pt_de_vie << endl;
    }
    else
    {
        cout << endl << nom_du_perso << " has insufficient energy to use Delta Attack." << endl;
    }
}

int Perso::EquipHelmet()
{
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
 
  // Etape 2 : connexion à la base de donne choisie, ici equipementsJames
  con->setSchema("equipementsJames");
 
  // Etape 3 : création d'un objet qui permet d'effectuer des requêtes sur la base
  stmt = con->createStatement();
 
  // Etape 4 : exécution d'une requete : ici on sélectionne tous les enregistrements
  // de la table Equiement qui ont un ID compris entre 1 et 4
  res = stmt->executeQuery("SELECT * FROM Equipment WHERE ID BETWEEN 1 AND 4;");
  
  // Etape 5 : exploitation du résultat de la requête
  if (res->next()) {
    cout <<"\nID:    "<< res->getInt("ID") << endl;
    cout <<"Type:    "<< res->getString("TYPEOFARMOR") << endl;
    cout <<"Health:  "<< res->getInt("Health") << endl;
    cout <<"Attack:  "<< res->getInt("Attack") << endl;
    cout <<"Defence: "<< res->getInt("Defence") << endl;
    cout <<"Speed:   "<< res->getInt("Speed") << "\n" << endl;

    cout <<"Before:  \n"<< nom_du_perso << endl << "Health: "  << nb_de_pt_de_vie << endl;
    cout <<"Attack:  " << attaque << endl;
    cout <<"Defence: " << defence << endl;
    cout <<"Speed:   " << vitesse << endl;
    cout <<"Energy:  " << energie << endl;

    nb_de_pt_de_vie += res->getInt("Health");
    attaque += res->getInt("Attack");
    defence += res->getInt("Defence");
    vitesse += res->getInt("Speed");

    cout <<"\nAfter:   \n"<< nom_du_perso << endl << "Health: "  << nb_de_pt_de_vie << endl;
    cout <<"Attack:  " << attaque << endl;
    cout <<"Defence: " << defence << endl;
    cout <<"Speed:   " << vitesse << endl;
    cout <<"Energy:  " << energie << endl;
    // Acces par non du champ de la table : ici le champ 'id' que l'on recupère au format string
    /*cout << res->getString("ID") << endl;
    cout << "MySQL la suite : ";
    // Acces à la donnée par son numéro de colonne, 1 étant le premier (ici 'id'), 5 le nom de l'animal
    /*cout << res->getString("TYPEOFARMOR") << endl;
    cout << "Health:    " << res->getString("Health") << endl;
    cout << "Attack:    " << res->getString("Attack") << endl;
    cout << "Defence:   " << res->getString("Defence") << endl;
    cout << "Speed:     " << res->getString("Speed") << endl;*/
  }
  // On nettoie tout avant de sortir : effacement des pointeurs
  // le pointeur sur le Driver sera effacé tout seul
  delete res;
  delete stmt;
  delete con;

  return EXIT_SUCCESS;
 
} catch (sql::SQLException &e) {
  // Gestion des execeptions pour déboggage
  cout << "# ERR: " << e.what();
  cout << " (code erreur MySQL: " << e.getErrorCode();
  cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
 
cout << endl;
 
// on sort en indiquant que tout c'est bien passé
return EXIT_SUCCESS;
}