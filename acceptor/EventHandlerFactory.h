//////////////////////////////////////////////////////////////////////////
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

#ifndef SIMPLE_REACTOR_ACCEPTOR_EVENTHANDLERFACTORY_H_
#define SIMPLE_REACTOR_ACCEPTOR_EVENTHANDLERFACTORY_H_

#include <reactor/EventHandler.h>

namespace reactor
{

class EventHandlerFactory
{
public:
  virtual ~EventHandlerFactory() {}
  virtual EventHandler *create (Reactor *reactor) = 0;
};

}


#endif // SIMPLE_REACTOR_EVENTHANDLERFACTORY_H_
