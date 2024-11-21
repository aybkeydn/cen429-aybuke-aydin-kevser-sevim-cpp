#include "ComicBookManager.h"
#include <iostream>
#include <algorithm>
#include <openssl/aes.h>
#include <cstring>

// Comic ekleme iþlevi
void ComicBookManager::addComic(const Comic& comic) {
    comics.push_back(comic);
    std::cout << "Comic added: " << comic.title << " by " << comic.author << std::endl;
}

// Comic listeleme iþlevi
void ComicBookManager::listComics() const {
    if (comics.empty()) {        std::cout << "No comics in the collection." << std::endl;
        return;
    }

    std::cout << "Comic Book Collection:" << std::endl;
    for (const auto& comic : comics) {
        std::cout << "Title: " << comic.title << ", Author: " << comic.author
            << ", Publisher: " << comic.publisher << ", Issue: " << comic.issue << std::endl;
    }
}

// Comic sifreleme
void encryptData(const unsigned char* plaintext, unsigned char* ciphertext, AES_KEY* enc_key) {
    AES_encrypt(plaintext, ciphertext, enc_key);
}

void secureErase(unsigned char* data, size_t length) {
    memset(data, 0, length); // Veriyi güvenli bir þekilde bellekte siler
}
