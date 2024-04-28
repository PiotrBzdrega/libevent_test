cmake_minimum_required(VERSION 3.5.0)
project(libevent_test VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SOURCES main.cpp)

cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH PARENT_DIR)


# # Add libevent library
# set(LIBEVENT_DIR ${PARENT_DIR}/libevent)
# find_path(LIBEVENT_INCLUDE event2/event.h HINTS ${LIBEVENT_DIR}/include)
# find_library(LIBEVENT_LIB NAMES event HINTS ${LIBEVENT_DIR}/build/lib/Release)


# # Check if libevent is found
# if(NOT LIBEVENT_INCLUDE OR NOT LIBEVENT_LIB)
#     message(FATAL_ERROR "libevent not found")
# endif()

# Link libevent library
# target_link_libraries(libevent_test PRIVATE ${LIBEVENT_LIB})

# Add the libevent include directory to include directories
# include_directories(libevent_test PUBLIC ${LIBEVENT_INCLUDE})

find_package(Libevent REQUIRED)

add_executable(libevent_test ${SOURCES})



# Link libevent library
#target_link_libraries(libevent_test PRIVATE ${LIBEVENT_LIB})

target_link_libraries(libevent_test libevent::core)

# install(FILES $<TARGET_RUNTIME_DLLS:libevent_test> TYPE BIN)

# Copy needed dlls to directory with .exe
add_custom_command(TARGET libevent_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:libevent_test> $<TARGET_FILE_DIR:libevent_test>
    COMMAND_EXPAND_LISTS
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
