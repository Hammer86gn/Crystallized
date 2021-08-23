project(UnitTest)
include_directories(../include)

add_executable(UnitTest src/testMain.cpp)
target_link_libraries(UnitTest Crystallized)