#include "ComicBookManager.h"
#include "DatabaseManager.h"
#include <iostream>

void displayMenu() {
    std::cout << "\nComic Book Collection Manager\n";
    std::cout << "1. Add Comic\n";
    std::cout << "2. List Comics\n";
    std::cout << "3. Delete Comic\n";
    std::cout << "4. Exit\n";
    std::cout << "Select an option: ";
}

int main() {
    // Veritabaný yolu
    DatabaseManager dbManager("src/sqlite/example_db.sqlite");

    // Veritabanýný aç ve tablo oluþtur
    if (!dbManager.openDatabase()) {
        return 1;
    }

    dbManager.createTable();

    ComicBookManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Comic comic;
            std::cout << "Enter title: ";
            std::cin >> comic.title;
            std::cout << "Enter author: ";
            std::cin >> comic.author;
            std::cout << "Enter publisher: ";
            std::cin >> comic.publisher;
            std::cout << "Enter issue number: ";
            std::cin >> comic.issue;

            dbManager.insertComic(comic.title, comic.author, comic.publisher, comic.issue);
            manager.addComic(comic);
            break;
        }
        case 2:
            manager.listComics();
            break;
        case 3: {
            std::string title;
            std::cout << "Enter title to delete: ";
            std::cin >> title;
            manager.deleteComic(title);
            break;
        }
        case 4:
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid option. Please enter a number between 1 and 4.\n";
            break;
        }
    } while (choice != 4);

    // Veritabaný baðlantýsýný kapat
    dbManager.closeDatabase();
    return 0;
}
