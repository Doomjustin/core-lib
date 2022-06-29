link_libraries(spdlog::spdlog fmt::fmt)

add_executable(test-catch2 test_catch2.cpp)
target_link_libraries(test-catch2 PRIVATE Catch2::Catch2WithMain)

add_executable(test-algorithm test_algorithm.cpp)
target_link_libraries(test-algorithm PRIVATE Catch2::Catch2WithMain)

add_executable(test-numeric test_numeric.cpp)
target_link_libraries(test-numeric PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

catch_discover_tests(test-catch2)
catch_discover_tests(test-algorithm)
catch_discover_tests(test-numeric)