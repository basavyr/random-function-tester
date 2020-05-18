add_library(operations SHARED add.cc operations.cc sqrt.cc trig.cc)
target_include_directories(operations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})