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

#ifndef OPEN_REACTOR_REACTOR_REACTORHANDLERFACTORY_H_
#define OPEN_REACTOR_REACTOR_REACTORHANDLERFACTORY_H_

#include <reactor/ReactorHandler.h>

namespace reactor
{

  class ReactorHandlerFactory
  {
  public:
    virtual ~ReactorHandlerFactory() {}
    virtual ReactorHandler *create(Reactor *reactor) = 0;
    virtual void destroy(Reactor *reactor,
                         ReactorHandler *handler) = 0;
  };

}

#endif /* reactor_ReactorHandlerFactory_h */
