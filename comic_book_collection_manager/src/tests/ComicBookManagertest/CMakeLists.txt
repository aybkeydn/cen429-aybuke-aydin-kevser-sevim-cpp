# tests/CMakeLists.txt

# Google Test için gerekli başlık dosyalarını ve kütüphaneyi dahil ediyoruz
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# comic_manager kütüphanesini ve Google Test'i kullanarak test çalıştırılabilir dosyasını oluşturuyoruz
add_executable(test_comic_manager comicmanagertest/test_comic_manager.cpp)

# test çalıştırılabilir dosyasını, comic_manager kütüphanesi ve Google Test kütüphanesi ile bağlantılıyoruz
target_link_libraries(test_comic_manager comic_manager gtest gtest_main)
