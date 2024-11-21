#include "database/sqlite/DatabaseManager.h"
#include <iostream>

int main() {
    // Veritabanı yolunu vererek DatabaseManager nesnesini oluşturun
    DatabaseManager dbManager("src/database/sqlite/example_db.sqlite");

    // Veritabanını aç
    if (!dbManager.openDatabase()) {
        std::cerr << "Failed to open database." << std::endl;
        return -1;
    }

    // Tabloyu oluştur
    if (dbManager.createTable()) {
        std::cout << "Table created successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to create table." << std::endl;
    }

    // Veritabanına veri ekleyin
    if (dbManager.insertComic("Batman", "Bob Kane", "DC Comics", 1)) {
        std::cout << "Comic inserted successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to insert comic." << std::endl;
    }

    // Veritabanını kapat
    dbManager.closeDatabase();

    return 0;
}
