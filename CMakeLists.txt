cmake_minimum_required(VERSION 2.8.4)
project(tictacs)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Get the current working branch
execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
# Get the current HEAD short sha1
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE REVISION
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Set version information in a config.h file
set(tictacs_VERSION_MAJOR 0)
set(tictacs_VERSION_MINOR 1)
if(REVISION)
  set(tictacs_VERSION_REVISION \"${REVISION}\")
else()
  set(tictacs_VERSION_REVISION nullptr)
endif()
if(BRANCH)
  set(tictacs_VERSION_BRANCH \"${BRANCH}\")
else()
  set(tictacs_VERSION_BRANCH nullptr)
endif()
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# Define sources and executable
set(EXECUTABLE_NAME "tictacs")
set(SOURCE_FILES main.cpp Entity.cpp SpriteComponent.cpp ShapeComponent.cpp ShaderComponent.cpp)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2.1 REQUIRED system window graphics network)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
  set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
  set(CPACK_PACKAGE_VERSION_MAJOR "${tictacs_VERSION_MAJOR}")
  set(CPACK_PACKAGE_VERSION_MINOR "${tictacs_VERSION_MINOR}")
include(CPack)

