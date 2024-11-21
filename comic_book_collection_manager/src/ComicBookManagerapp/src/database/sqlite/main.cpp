#include "database/sqlite/DatabaseManager.h"
#include <iostream>

int main() {
    // Veritaban� yolunu vererek DatabaseManager nesnesini olu�turun
    DatabaseManager dbManager("src/database/sqlite/example_db.sqlite");

    // Veritaban�n� a�
    if (!dbManager.openDatabase()) {
        std::cerr << "Failed to open database." << std::endl;
        return -1;
    }

    // Tabloyu olu�tur
    if (dbManager.createTable()) {
        std::cout << "Table created successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to create table." << std::endl;
    }

    // Veritaban�na veri ekleyin
    if (dbManager.insertComic("Batman", "Bob Kane", "DC Comics", 1)) {
        std::cout << "Comic inserted successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to insert comic." << std::endl;
    }

    // Veritaban�n� kapat
    dbManager.closeDatabase();

    return 0;
}
