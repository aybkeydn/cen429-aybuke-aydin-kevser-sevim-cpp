#ifndef DATABASE_MANAGER_H 
#define DATABASE_MANAGER_H

#include <string>
#include <sqlite3.h>

class DatabaseManager {
public:
    DatabaseManager(const std::string& dbPath);
    ~DatabaseManager();

    bool openDatabase();  // Veritaban�n� a�
    void closeDatabase(); // Veritaban�n� kapat
    bool createTable();   // Tablo olu�tur
    bool insertComic(const std::string& title, const std::string& author, const std::string& publisher, int issue);

private:
    sqlite3* db;          // Veritaban� ba�lant�s� i�aret�isi
    std::string dbPath;   // Veritaban� dosya yolu
};

#endif // DATABASE_MANAGER_H
