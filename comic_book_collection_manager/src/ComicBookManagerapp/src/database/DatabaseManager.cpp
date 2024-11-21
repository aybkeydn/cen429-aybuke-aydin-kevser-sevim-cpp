#include "DatabaseManager.h"
#include "sqlite/sqlite3.h"
#include <iostream>

DatabaseManager::DatabaseManager(const std::string& dbPath) : db(nullptr), dbPath(dbPath) {
    openDatabase();
}

DatabaseManager::~DatabaseManager() {
    closeDatabase();
}

bool DatabaseManager::openDatabase() {
    int exit = sqlite3_open(dbPath.c_str(), &db);
    if (exit != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    else {
        std::cout << "Opened database successfully!" << std::endl;
        return true;
    }
}

void DatabaseManager::closeDatabase() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool DatabaseManager::createTable() {
    std::string sql = "CREATE TABLE IF NOT EXISTS COMIC ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "TITLE TEXT NOT NULL, "
        "AUTHOR TEXT NOT NULL, "
        "PUBLISHER TEXT NOT NULL, "
        "ISSUE INTEGER NOT NULL);";

    char* messageError = nullptr;
    int exit = sqlite3_exec(db, sql.c_str(), nullptr, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error creating table: " << messageError << std::endl;
        sqlite3_free(messageError);
        return false;
    }
    else {
        std::cout << "Table created successfully!" << std::endl;
        return true;
    }
}

bool DatabaseManager::insertComic(const std::string& title, const std::string& author, const std::string& publisher, int issue) {
    const char* sql = "INSERT INTO COMIC (TITLE, AUTHOR, PUBLISHER, ISSUE) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    // SQL sorgusunu hazırla
    int exit = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (exit != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Parametreleri bağla
    sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, author.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, publisher.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, issue);

    // Sorguyu çalıştır
    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }
    else {
        std::cout << "Comic inserted successfully!" << std::endl;
    }

    // Belleği serbest bırak
    sqlite3_finalize(stmt);
    return true;
}
