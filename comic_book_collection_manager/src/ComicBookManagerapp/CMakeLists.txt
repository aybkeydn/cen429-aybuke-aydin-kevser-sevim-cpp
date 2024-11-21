# src/projeadiApp CMakeLists.txt
set(APPNAME projeadiapp)

message(STATUS "[${APPNAME}] Module Processing...")

# Collect files without having to explicitly list each header and source file
file(GLOB APP_HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/header/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/header/*.hpp")

file(GLOB APP_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")

# Create named folders for the sources within the project
source_group("header" FILES ${APP_HEADERS})
source_group("src" FILES ${APP_SOURCES})

# Set Properties->General->Configuration Type to Executable
add_executable(${APPNAME} ${APP_HEADERS} ${APP_SOURCES}) # Create executable

# Include directories
target_include_directories(${APPNAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../utility/header
                           ${CMAKE_CURRENT_SOURCE_DIR}/../ComicBookManager/header
                           ${CMAKE_CURRENT_SOURCE_DIR}/header)

# Link the projeadi library
target_link_libraries(${APPNAME} PRIVATE ComicBookManager)

# Install the executable
install(TARGETS ${APPNAME}
        RUNTIME DESTINATION bin)

message(STATUS "[${APPNAME}] Added Executable target: ${APPNAME}")