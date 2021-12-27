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
#ifndef SIMPLE_REACTOR_ACCEPTOR_ACCEPTORTHREAD_H_
#define SIMPLE_REACTOR_ACCEPTOR_ACCEPTORTHREAD_H_

#include <acceptor/Acceptor.h>
#include <acceptor/EventHandlerFactory.h>

#include <reactor/ReactorHandlerFactory.h>
#include <reactor/ReactorThread.h>
#include <reactor/ObjectsTimer.h>

#include <cstdio>
#include <thread>
#include <unordered_map>
#include <mutex>
#include <condition_variable>

namespace reactor
{

  class AcceptorThread
  {
  public:
    AcceptorThread(Acceptor &acceptor,
                   ReactorThread *reactor_thread,
                   EventHandlerFactory &event_handler_factory);

    ~AcceptorThread();

    void start();
    void stop();

  protected:
    void run();

  private:
    Acceptor &acceptor_;
    ReactorThread *reactor_thread_;
    EventHandlerFactory &handler_factory_;

  private:
    std::thread *thread_ = nullptr;
  };

  inline AcceptorThread::AcceptorThread(Acceptor &acceptor,
                                        ReactorThread *reactor_thread,
                                        EventHandlerFactory &event_handler_factory)
      : acceptor_(acceptor),
        reactor_thread_(reactor_thread),
        handler_factory_(event_handler_factory)
  {
  }

  inline AcceptorThread::~AcceptorThread()
  {
    if (thread_ != nullptr)
      delete thread_;
  }

  inline void
  AcceptorThread::start()
  {
    if (thread_ != nullptr)
      delete thread_;

    thread_ = new std::thread{&AcceptorThread::run, this};
  }

  inline void
  AcceptorThread::stop()
  {
    acceptor_.close();
    thread_->join();
    delete thread_;
    thread_ = nullptr;
  }

}

#endif // SIMPLE_REACTOR_ACCEPTOR_ACCEPTORTHREAD_H_
