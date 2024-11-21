#ifndef COMIC_BOOK_MANAGER_H
#define COMIC_BOOK_MANAGER_H

#include <string>
#include <vector>

// Çizgi roman verilerini temsil eden Comic yapýsý
struct Comic {
    std::string title;       // Çizgi roman baþlýðý
    std::string author;      // Çizgi roman yazarý
    std::string publisher;   // Çizgi romanýn yayýncýsý
    int issue;               // Çizgi romanýn sayý numarasý
};

// Çizgi roman koleksiyonunu temsil eden sýnýf
class ComicBookManager {
public:
    // Yeni bir çizgi roman koleksiyona ekler
    void addComic(const Comic& comic);

    // Tüm çizgi romanlarý listeler
    void listComics() const;

    // Baþlýða göre çizgi roman siler
    bool deleteComic(const std::string& title);

    // Koleksiyondaki tüm çizgi romanlarý döndürür (test için)
    const std::vector<Comic>& getComics() const;

private:
    std::vector<Comic> comics; // Çizgi romanlarý depolayan vektör
};

#endif // COMIC_BOOK_MANAGER_H
