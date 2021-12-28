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

#ifndef SIMPLE_REACTOR_REACTOR_REACTORTHREAD_H_
#define SIMPLE_REACTOR_REACTOR_REACTORTHREAD_H_

#include <reactor/Reactor.h>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace reactor
{

  class ReactorThread
  {
  public:
    Reactor reactor;

    ~ReactorThread();

    bool init(const size_t &max_clients_per_reactor,
              const size_t &max_events_per_reactor);

    void start();

    void stop();

    bool is_run() const;

  protected:
    void run();

  private:
    std::thread *thread_ = nullptr;

  private:
    std::condition_variable condition_;
    std::mutex condition_lock_;
    bool is_run_ = false;
  };

}

#endif // SIMPLE_REACTOR_REACTOR_REACTORTHREAD_H_
