#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

int main() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    // Établir la connexion à la base de données
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "AT1978@vlf");

    // Sélectionner la base de données (changez "nom_de_votre_base" par le nom de votre base de données)
    con->setSchema("foodly2");

    // Créer une table
    sql::Statement *stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS exemple (id INT AUTO_INCREMENT, nom VARCHAR(50), age INT, PRIMARY KEY (id))");
    delete stmt;

    // Insérer des données dans la table
    stmt = con->createStatement();
    stmt->execute("INSERT INTO exemple (nom, age) VALUES ('John Doe', 30)");
    stmt->execute("INSERT INTO exemple (nom, age) VALUES ('Jane Smith', 25)");
    delete stmt;

    // Récupérer des données de la table
    stmt = con->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT * FROM exemple");
    while (res->next()) {
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
