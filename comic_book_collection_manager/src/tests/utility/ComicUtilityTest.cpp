// ComicUtilityTest.cpp - Test cases for Comic Book Manager security utility functions

#include "gtest/gtest.h"
#include "../header/ComicUtility.h"
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <iostream>
#include <string>

using namespace ComicBookManager::Utility;

// Helper function to create an RSA key for testing
RSA* generateTestRSAKey() {
    RSA* rsa = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);
    return rsa;
}

// Test for RSA encryption
TEST(ComicUtilityTest, RSAEncryptTest) {
    RSA* rsa = generateTestRSAKey();
    std::string data = "Test data for encryption";
    std::string encryptedData = rsaEncrypt(data, rsa);

    // Check that the encrypted data is not empty and is different from the original data
    EXPECT_FALSE(encryptedData.empty());
    EXPECT_NE(encryptedData, data);

    RSA_free(rsa);
}

// Test for debugger detection
TEST(ComicUtilityTest, DebuggerDetectionTest) {
    bool debuggerPresent = isDebuggerPresent();

    // Assuming no debugger is attached during this test, so we expect false
    EXPECT_FALSE(debuggerPresent);
}

// Test for SSL/TLS initialization
TEST(ComicUtilityTest, SSLInitializationTest) {
    bool sslInitialized = initializeSSL();

    // Check if SSL initialization is successful
    EXPECT_TRUE(sslInitialized);
}

// Placeholder test for Whitebox AES encryption
TEST(ComicUtilityTest, WhiteboxAESEncryptTest) {
    std::string data = "Sensitive data for whitebox encryption";

    // Since whiteboxEncryptData is a placeholder, we just verify the function exists and runs
    ASSERT_NO_THROW(whiteboxEncryptData(data));
}

