# tests/CMakeLists.txt

# Google Test için gerekli baþlýk dosyalarýný ve kütüphaneyi dahil ediyoruz
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# comic_manager kütüphanesini ve Google Test'i kullanarak test çalýþtýrýlabilir dosyasýný oluþturuyoruz
add_executable(test_comic_manager comicmanagertest/test_comic_manager.cpp)

# test çalýþtýrýlabilir dosyasýný, comic_manager kütüphanesi ve Google Test kütüphanesi ile baðlantýlýyoruz
target_link_libraries(test_comic_manager comic_manager gtest gtest_main)
