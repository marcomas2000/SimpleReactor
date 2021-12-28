/////////////////////////////////////////////////////////////////////////
// Copyright 2021 Marco Mascioli
/////////////////////////////////////////////////////////////////////////
/************************************************************************
    This file is part of 
    SIMPLE_REACTOR (https://github.com/marcomas2000/simple_reactor)

    This work was originally based the project 
    https://github.com/ty7swkr/open_reactor
    though the structure and the content of the project has been
    widely modified.

    SIMPLE_REACTOR is free software: you can use it under the terms of 
    the MIT license as described in the file LICENSE.
************************************************************************/
#ifndef SIMPLE_REACTOR_REACTOR_TRACE_H_
#define SIMPLE_REACTOR_REACTOR_TRACE_H_

#include <iostream>

#ifndef reactor_trace
#define reactor_trace std::cout << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << ":" << ": "
#endif

#endif // SIMPLE_REACTOR_REACTOR_TRACE_H_
