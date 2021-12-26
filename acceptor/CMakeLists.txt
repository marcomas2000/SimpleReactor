add_library (acceptor STATIC  Acceptor.cpp AcceptorThread.cpp)
set (CMAKE_CXX_FLAGS "-D_REENTRANT -O2 -std=c++11 -Wall -Wextra -Wfloat-equal -m64")
target_include_directories(acceptor PUBLIC ${PROJECT_SOURCE_DIR} )