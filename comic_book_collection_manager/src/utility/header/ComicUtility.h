// ComicUtility.h - Comic Book Manager utilities for security functions

#ifndef COMIC_UTILITY_H
#define COMIC_UTILITY_H

#include <string>
#include <openssl/rsa.h>

// RSA encryption function declaration
std::string rsaEncrypt(const std::string& data, RSA* rsa);

// Whitebox AES encryption function placeholder
void whiteboxEncryptData(const std::string& data);

// Function to detect if a debugger is present
bool isDebuggerPresent();

// Function to initialize SSL/TLS connection
bool initializeSSL();

#endif // COMIC_UTILITY_H
