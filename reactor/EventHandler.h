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

#ifndef SIMPLE_REACTOR_REACTOR_EVENTHANDLER_H_
#define SIMPLE_REACTOR_REACTOR_EVENTHANDLER_H_

#include <reactor/DefinedType.h>
#include <string>

namespace reactor
{

  class Reactor;

  class EventHandler
  {
  public:
    EventHandler() {}
    virtual ~EventHandler() {}

  protected:
    // Called when registered in Reactor.
    // There is no need to register with Reactor as it is already registered with Reactor.
    virtual void register_handler(Reactor *reactor, const io_handle_t &io_handle) = 0;

    // Called when removed from Reactor.
    virtual void handle_removed(Reactor *reactor) = 0;

    // Called when data arrives.
    virtual void handle_input(Reactor *reactor) = 0;

    // Called when data can be written.
    virtual void handle_output(Reactor *reactor) = 0;

    // Called by Reactor when the client is disconnected.
    // handle_close() is still called until user explicitly
    // call close(io_handle_) or shutdown(io_handle_, ...).
    virtual void handle_close(Reactor *reactor) = 0;

    // When Reactor's set_timeout(msec) is called,
    // Reactor calls handle_timeout() after the timeout.
    // set_timeout is one-time. To call handle_timeout again,
    // you must call Reactor::set_timeout(msec) each time.
    virtual void handle_timeout(Reactor *reactor) = 0;

    // Called on error. The error is set to the standard errno.
    virtual void handle_error(Reactor *reactor, const int &error_no = 0, const std::string &error_str = "") = 0;

    // Called when the reactor is shutting down. The reactor is set to nullptr.
    virtual void handle_shutdown(Reactor *reactor) = 0;

  protected:
    io_handle_t io_handle_ = INVALID_IO_HANDLE;
    friend class Reactor;
  };

}

#endif // SIMPLE_REACTOR_REACTOR_EVENTHANDLER_H_
