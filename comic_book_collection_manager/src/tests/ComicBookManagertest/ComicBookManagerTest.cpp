// ComicBookManagerTest.cpp - Test cases for Comic Book Manager functions

#include "gtest/gtest.h"
#include "../header/ComicBookManager.h"
#include "../header/ComicUtility.h"

// Collection management tests

// Test for adding a comic
TEST(ComicBookManagerTest, AddComic) {
    ComicBookManager manager;
    Comic comic{ "Batman", "Bob Kane", "DC Comics", 1 };

    manager.addComic(comic);

    // Check if the comic was added successfully
    ASSERT_EQ(manager.getComics().size(), 1);
    EXPECT_EQ(manager.getComics()[0].title, "Batman");
}

// Test for listing comics
TEST(ComicBookManagerTest, ListComics) {
    ComicBookManager manager;
    Comic comic1{ "Spider-Man", "Stan Lee", "Marvel", 1 };
    Comic comic2{ "Superman", "Jerry Siegel", "DC Comics", 1 };

    manager.addComic(comic1);
    manager.addComic(comic2);

    // Check the number and order of added comics
    ASSERT_EQ(manager.getComics().size(), 2);
    EXPECT_EQ(manager.getComics()[0].title, "Spider-Man");
    EXPECT_EQ(manager.getComics()[1].title, "Superman");
}

// Test for deleting a comic
TEST(ComicBookManagerTest, DeleteComic) {
    ComicBookManager manager;
    Comic comic{ "Batman", "Bob Kane", "DC Comics", 1 };

    manager.addComic(comic);
    manager.deleteComic("Batman");

    // Check if the comic was deleted successfully
    EXPECT_EQ(manager.getComics().size(), 0);
}

// Test for trying to delete a non-existent comic
TEST(ComicBookManagerTest, DeleteNonExistentComic) {
    ComicBookManager manager;
    manager.deleteComic("NonExistent");

    // The list should remain empty since the comic doesn't exist
    EXPECT_EQ(manager.getComics().size(), 0);
}

// Security-related tests using ComicUtility

// Test for RSA encryption
TEST(ComicUtilityTest, RSAEncryptTest) {
    RSA* rsa = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);
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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
