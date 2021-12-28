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

#ifndef SIMPLE_REACTOR_REACTOR_DEFINEDTYPE_H_
#define SIMPLE_REACTOR_REACTOR_DEFINEDTYPE_H_

#include <stdint.h>
#include <stddef.h>

namespace reactor
{

    constexpr int INVALID_IO_HANDLE = -1;
    typedef int32_t io_handle_t;

}

#endif // SIMPLE_REACTOR_REACTOR_DEFINEDTYPE_H_
