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
#include "ReactorHandler.h"
#include "Reactor.h"

using namespace reactor;

bool ReactorHandler::set_timeout(const uint32_t &msec)
{
  if (reactor_ == nullptr)
    return false;

  return reactor_->set_timeout(this, msec);
}

void ReactorHandler::unset_timeout()
{
  if (reactor_ == nullptr)
    return;

  reactor_->unset_timeout(this);
}

void ReactorHandler::reactor_handle_shutdown(Reactor *reactor) 
{ 
  (void)reactor; 
}

void ReactorHandler::reactor_handle_error(Reactor *reactor,
                                  const int &error_no,
                                  const std::string &error_str)
{
  (void)reactor, (void)error_no, (void)error_str;
}

void ReactorHandler::reactor_handle_registered_handler(Reactor *reactor, EventHandler *handler)
{
  (void)reactor, (void)handler;
}

void ReactorHandler::reactor_handle_removed_handler(Reactor *reactor, EventHandler *handler)
{
  (void)reactor, (void)handler;
}
