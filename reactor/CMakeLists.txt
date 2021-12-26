add_library (reactor STATIC  Reactor.cpp Reactors.cpp ReactorHandler.cpp)
set (CMAKE_CXX_FLAGS "-D_REENTRANT -O2 -std=c++11 -Wall -Wextra -Wfloat-equal -m64")
target_include_directories(reactor PUBLIC ${PROJECT_SOURCE_DIR} )