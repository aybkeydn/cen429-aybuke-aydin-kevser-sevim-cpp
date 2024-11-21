/**
 * @file ComicUtility.cpp
 *
 * @brief Provides utility functions for encryption, debugging detection, and SSL/TLS initialization
 */

#include <cstring>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <csignal>
#include <iostream>
#include <unistd.h>

#include "../header/ComicUtility.h"

using namespace ComicBookManager::Utility;

// RSA �ifreleme fonksiyonu
std::string rsaEncrypt(const std::string& data, RSA* rsa) {
    int dataSize = RSA_size(rsa);
    std::string encrypted(dataSize, '\0');
    int result = RSA_public_encrypt(data.size(), (const unsigned char*)data.c_str(),
        (unsigned char*)encrypted.c_str(), rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        ERR_print_errors_fp(stderr);
    }
    return encrypted;
}

// Whitebox AES kullanarak veri �ifreleme (placeholder)
// Whitebox AES i�in �zel bir k�t�phane entegrasyonu gerekmektedir
void whiteboxEncryptData(const std::string& data) {
    // Whitebox k�t�phanesi entegrasyon kodu buraya eklenecek
}

// Hata ay�klay�c� tespit etme fonksiyonu
bool isDebuggerPresent() {
    return (ptrace(PTRACE_TRACEME, 0, NULL, 0) == -1);
}

// SSL/TLS ba�lant�s� ba�latma fonksiyonu
bool initializeSSL() {
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        return false;
    }

    if (SSL_CTX_load_verify_locations(ctx, "certificate.pem", NULL) != 1) {
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return false;
    }

    SSL_CTX_free(ctx);
    return true;
}

// Uygulama ana i�levi
int main() {
    // Hata ay�klay�c� tespiti
    if (isDebuggerPresent()) {
        std::cout << "Hata ay�klay�c� tespit edildi. ��k�l�yor.\n";
        return 1;
    }

    // SSL/TLS ba�latma
    if (!initializeSSL()) {
        std::cout << "SSL/TLS ba�lat�lamad�.\n";
        return 1;
    }

    std::cout << "Uygulama g�venli �ekilde �al���yor.\n";
    return 0;
}
