////////////////////////////////////////////////////////////
//  Dans le terminal:
//  installer le connecteur avec: 
//  sudo apt install libmysqlcppconn
//  puis compliler avec
//  g++ -o test test.cpp Wall -lmysqlcppconn
//  executer avec ./test
///////////////////////////////////////////////////////////


#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

///////////////pour envoyer des commandes sur le terminal ///////////
#include <cstdlib>
#include <cstring>

int main() {
    /*******************************
    std::cout << "Ce programme va effectuer des opérations nécessitant des privilèges root." << std::endl;

    // Exécutez une commande en utilisant sudo
    const char* command = "sudo whoami"; // Exemple : "whoami" est exécuté avec sudo
    std::cout << "Exécution de la commande : " << command << std::endl;

    // Utilisation de la fonction système pour exécuter la commande en tant que sudo
    int result = std::system(command);

    if (result != 0) {
        std::cerr << "Erreur lors de l'exécution de la commande." << std::endl;
    } else {
        std::cout << "Commande exécutée avec succès." << std::endl;
    }

    *********************************/

    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    // Établir la connexion à la base de données
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "student", "crif2024sn");

    // Sélectionner la base de données (changez "nom_de_votre_base" par le nom de votre base de données)
    con->setSchema("foodly2");

    // Créer une table
    sql::Statement *stmt;
    stmt = con->createStatement();  
    stmt->execute("CREATE TABLE IF NOT EXISTS exemple (id INT AUTO_INCREMENT, nom VARCHAR(50), age INT, PRIMARY KEY (id))");
    delete stmt;

    // Insérer des données dans la table
    stmt = con->createStatement();
    //stmt->execute("INSERT INTO exemple (nom, age) VALUES ('John Doe', 30)");
    //stmt->execute("INSERT INTO exemple (nom, age) VALUES ('Jane Smith', 25)");
    delete stmt;

    // Récupérer des données de la table
    stmt = con->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT * FROM exemple");
    while (res->next()) {// la methode next() de l'objet ResultSet est utilisée pour passer a la ligne suivante
    //si next renvoie true on continue sinon on s'arrete.
        std::cout << "ID: " << res->getInt("id");
        std::cout << ", Nom: " << res->getString("nom");
        std::cout << ", Âge: " << res->getInt("age") << std::endl;
    }
    delete res;
    delete stmt;

    con->close();
    delete con;

    return 0;
}
