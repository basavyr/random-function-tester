add_executable(math_test ../../src/math/math.cc math_tests.cc)
target_link_libraries(math_test LINK_PUBLIC math)