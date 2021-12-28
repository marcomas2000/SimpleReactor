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
#include "ReactorThread.h"
#include "reactor/trace.h"

namespace reactor
{

    bool ReactorThread::init(const size_t &max_clients_per_reactor,
                             const size_t &max_events_per_reactor)
    {
        reactor.init(max_clients_per_reactor,
                     max_events_per_reactor);

        return true;
    }

    ReactorThread::~ReactorThread()
    {
        if (thread_ != nullptr)
            delete thread_;
    }

    void ReactorThread::start()
    {
        reactor_trace << "Start Reactor Thread..." << std::endl;
        thread_ = new std::thread{&ReactorThread::run, this};
        std::unique_lock<std::mutex> lock(condition_lock_);
        if (is_run_ == true)
            return;

        condition_.wait(lock);
    }

    void ReactorThread::stop()
    {
        reactor.stop();
        thread_->join();
        delete thread_;
        thread_ = nullptr;
    }

    bool ReactorThread::is_run() const
    {
        return is_run_;
    }

    void ReactorThread::run()
    {
        {
            std::unique_lock<std::mutex> lock(condition_lock_);
            is_run_ = true;
            condition_.notify_all();
        }
        reactor_trace << "About to start Reactor run()..." << std::endl;
        reactor.run();
    }

}