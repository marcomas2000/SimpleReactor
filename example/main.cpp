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
#include "SvcHandler.h"
#include <reactor/trace.h>


using namespace reactor;


int main(void)
{
  ReactorThread* reactor_thread = new ReactorThread;

  Acceptor acc;
  acc.listen_ipv46(2000);
  reactor_trace << "Listening..." << std::endl;

  Svc_HandlerFactory svc_factory;
  reactor_thread->init(1000, 500);

  reactor_thread->start();
  AcceptorThread *accThread;
  accThread = new AcceptorThread(acc,
                                 reactor_thread,
                                 svc_factory);
  accThread->start();

  while (true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  accThread->stop();
  delete accThread;

  return 0;
}
