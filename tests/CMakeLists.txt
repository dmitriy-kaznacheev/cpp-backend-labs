find_package(GTest REQUIRED CONFIG)

add_executable(unit_tests
  test_env_ci.cpp
)

target_link_libraries(unit_tests PRIVATE
  multiply
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)