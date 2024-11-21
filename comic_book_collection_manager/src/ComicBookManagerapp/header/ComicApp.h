#ifndef COMIC_BOOK_MANAGER_H
#define COMIC_BOOK_MANAGER_H

#include <string>
#include <vector>

// �izgi roman verilerini temsil eden Comic yap�s�
struct Comic {
    std::string title;       // �izgi roman ba�l���
    std::string author;      // �izgi roman yazar�
    std::string publisher;   // �izgi roman�n yay�nc�s�
    int issue;               // �izgi roman�n say� numaras�
};

// �izgi roman koleksiyonunu temsil eden s�n�f
class ComicBookManager {
public:
    // Yeni bir �izgi roman koleksiyona ekler
    void addComic(const Comic& comic);

    // T�m �izgi romanlar� listeler
    void listComics() const;

    // Ba�l��a g�re �izgi roman siler
    bool deleteComic(const std::string& title);

    // Koleksiyondaki t�m �izgi romanlar� d�nd�r�r (test i�in)
    const std::vector<Comic>& getComics() const;

private:
    std::vector<Comic> comics; // �izgi romanlar� depolayan vekt�r
};

#endif // COMIC_BOOK_MANAGER_H
