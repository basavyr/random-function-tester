add_executable(geometry ../../src/geometry/rectangle.cc geometry_test.cc)
target_link_libraries(geometry LINK_PUBLIC geometry_libs)