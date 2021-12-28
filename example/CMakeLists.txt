#//////////////////////////////////////////////////////////////////////////
#// Copyright 2021 Marco Mascioli
#/////////////////////////////////////////////////////////////////////////
#/************************************************************************
#    This file is part of 
#    SIMPLE_REACTOR (https://github.com/marcomas2000/simple_reactor)
#
#    This work was originally based the project 
#    https://github.com/ty7swkr/open_reactor
#    though the structure and the content of the project has been
#    widely modified.
#
#    SIMPLE_REACTOR is free software: you can use it under the terms of 
#    the MIT license as described in the file LICENSE.
#************************************************************************/
add_executable (simple_reactor main.cpp SvcHandler.cpp)

set (CMAKE_CXX_FLAGS "-D_REENTRANT -O2 -std=c++11 -Wall -Wextra -Wfloat-equal -m64")
target_include_directories(simple_reactor PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(simple_reactor LINK_PUBLIC acceptor reactor rt pthread crypto)