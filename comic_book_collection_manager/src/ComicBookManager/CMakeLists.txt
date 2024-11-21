# src/ComicBookManager CMakeLists.txt
set(LIBNAME ComicBookManager)

message(STATUS "[${LIBNAME}] Module Processing...")

# Collect files without having to explicitly list each header and source file
file(GLOB LIB_HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/header/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/header/*.hpp")

file(GLOB LIB_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Create named folders for the sources within the project
source_group("Header Files" FILES ${LIB_HEADERS})
source_group("Source Files" FILES ${LIB_SOURCES})

# Set Properties->General->Configuration Type to Dynamic Library (.dll/.so/.dylib)
add_library(${LIBNAME} SHARED ${LIB_HEADERS} ${LIB_SOURCES}) # Create dynamic library (DLL)

# Include directories
target_include_directories(${LIBNAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../utility/header
                           ${CMAKE_CURRENT_SOURCE_DIR}/header)

# Creates preprocessor definition used for library exports
target_compile_definitions(${LIBNAME} PUBLIC COMICBOOKMANAGER_LIB_EXPORTS)

# Add any dependencies or compile options specific to comicbookmanager
target_compile_options(${LIBNAME} PRIVATE -DSQLITE_ENABLE_COLUMN_METADATA)

# Install targets
install(TARGETS ${LIBNAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

# Copy required header to the installation include folder
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/header/ComicBookManager.h
        DESTINATION include)

