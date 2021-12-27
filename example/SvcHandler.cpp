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
#include "SvcHandler.h"

namespace reactor
{
    Svc_Handler::~Svc_Handler()
    {
    }

    void Svc_Handler::register_handler(Reactor *reactor, const io_handle_t &io_handle) 
    {
        (void)reactor;
        reactor_trace << io_handle_ << "==" << io_handle << ", " << reactor->handler_count() << std::endl;
    }

    void Svc_Handler::handle_input(Reactor *reactor) 
    {
        memset(buff_, 0x00, sizeof(buff_));

        reactor_trace << ::recv(io_handle_, buff_, sizeof(buff_), 0) << std::endl;
        reactor_trace << buff_ << std::endl;

        // Register to write to the reactor.
        reactor->register_writable(this);
    }

    void Svc_Handler::handle_output(Reactor *reactor) 
    {
        (void)reactor;
        reactor_trace << ::send(io_handle_, buff_, strlen(buff_), 0) << std::endl;
    }

    void Svc_Handler::handle_close(Reactor *reactor) 
    {
        (void)reactor;
        reactor_trace << std::endl;
        reactor->remove_event_handler(this);
    }

    void Svc_Handler::handle_timeout(Reactor *reactor) 
    {
        (void)reactor;
        reactor_trace << std::endl;
    }

    void Svc_Handler::handle_error(Reactor *reactor, const int &error_no, const std::string &error_str) 
    {
        (void)reactor;
        reactor_trace << error_no << " " << error_str << std::endl;
    }

    void Svc_Handler::handle_shutdown(Reactor *reactor) 
    {
        (void)reactor;
        reactor_trace << std::endl;
    }

    void Svc_Handler::handle_removed(Reactor *reactor) 
    {
        (void)reactor;
        reactor_trace << std::endl;
        ::close(io_handle_);
        delete this;
    }

} // end namespace reactor
