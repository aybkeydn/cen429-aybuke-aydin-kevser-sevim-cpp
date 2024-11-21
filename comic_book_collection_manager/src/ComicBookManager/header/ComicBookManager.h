/// ComicBookManager.h
#ifndef COMIC_MANAGER_H
#define COMIC_MANAGER_H

#include <string>
#include <vector>

struct Comic {
    std::string title;
    std::string author;
    std::string publisher;
    int issue;
};

class ComicBookManager {
public:
    void addComic(const Comic& comic);
    void listComics() const;
    void deleteComic(const std::string& title);
private:
    std::vector<Comic> comics;
};

#endif // COMIC_BOOK_MANAGER_H
