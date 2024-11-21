#ifndef DATABASE_MANAGER_H 
#define DATABASE_MANAGER_H

#include <string>
#include <sqlite3.h>

class DatabaseManager {
public:
    DatabaseManager(const std::string& dbPath);
    ~DatabaseManager();

    bool openDatabase();  // Veritabanýný aç
    void closeDatabase(); // Veritabanýný kapat
    bool createTable();   // Tablo oluþtur
    bool insertComic(const std::string& title, const std::string& author, const std::string& publisher, int issue);

private:
    sqlite3* db;          // Veritabaný baðlantýsý iþaretçisi
    std::string dbPath;   // Veritabaný dosya yolu
};

#endif // DATABASE_MANAGER_H
