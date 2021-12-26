add_executable (simple_reactor main.cpp)

set (CMAKE_CXX_FLAGS "-D_REENTRANT -O2 -std=c++11 -Wall -Wextra -Wfloat-equal -m64")
target_include_directories(simple_reactor PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(simple_reactor LINK_PUBLIC acceptor reactor rt pthread crypto)