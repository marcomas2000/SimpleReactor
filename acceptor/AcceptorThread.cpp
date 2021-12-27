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
#include "AcceptorThread.h"
#include <reactor/trace.h>

// tcp nodelay
#include <linux/socket.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <sys/socket.h>

namespace reactor
{

  void
  AcceptorThread::run()
  {
    io_handle_t client_io_handle = INVALID_IO_HANDLE;
    struct ::sockaddr_storage client_addr;

    EventHandler *event_handler = nullptr;

    while (true)
    {
      int32_t min_timeout = -1;

      reactor_trace << "Accepting..." << std::endl;
      client_io_handle = acceptor_.accept(client_addr, min_timeout);

      // timeout
      if (client_io_handle == 0)
        continue;

      if (client_io_handle < 0)
        break;

      static int enable = 1;
      setsockopt(client_io_handle, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));
      setsockopt(client_io_handle, IPPROTO_TCP, TCP_NODELAY, &enable, sizeof(int));

      event_handler = handler_factory_.create(&(reactor_thread_->reactor));
      if (event_handler == nullptr)
      {
        ::close(client_io_handle);
        return;
      }

      reactor_trace << "registering event handler with reactor..." << std::endl;
      (&reactor_thread_->reactor)->register_event_handler(event_handler, client_io_handle);
    }
  }

}
