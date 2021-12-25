/*
 * main.cpp
 *
 *  Created on: 2021. 7. 26.
 *      Author: tys
 */

#include <acceptor/AcceptorThread.h>
#include <reactor/Reactors.h>
#include <reactor/trace.h>

#include <string.h>

using namespace reactor;

// client handler
class Svc_Handler : public EventHandler
{
protected:
  virtual ~Svc_Handler() {}
  // When a new connection is created and registered with the reactor.
  void register_handle(Reactor *reactor, const io_handle_t &io_handle) override
  {
    (void)reactor;
    reactor_trace << io_handle_ << "==" << io_handle << ", " << reactor->handler_count() << std::endl;
  }

  // Callback from the reactor when data are available
  void handle_input(Reactor *reactor) override
  {
    memset(buff_, 0x00, sizeof(buff_));

    reactor_trace << ::recv(io_handle_, buff_, sizeof(buff_), 0) << std::endl;
    reactor_trace << buff_ << std::endl;

    // Register to write to the reactor.
    reactor->register_writable(this);
  }

  // Called when writing is possible.
  void handle_output(Reactor *reactor) override
  {
    (void)reactor;
    reactor_trace << ::send(io_handle_, buff_, strlen(buff_), 0) << std::endl;
  }

  // Callback from the Reactor when the client is disconnected.
  void handle_close(Reactor *reactor) override
  {
    (void)reactor;
    reactor_trace << std::endl;
    reactor->remove_event_handler(this);
  }

  // When Reactor's set_timeout(msec) is called,
  // Reactor calls handle_timeout() after the timeout.
  // set_timeout is one-time. If you want to call handle_timeout repeatedly,
  // you must call Reactor::set_timeout(msec) each time.
  void handle_timeout(Reactor *reactor) override
  {
    (void)reactor;
    reactor_trace << std::endl;
  }

  // Called on error. The error is set to the standard errno.
  void handle_error(Reactor *reactor, const int &error_no = 0, const std::string &error_str = "") override
  {
    (void)reactor;
    reactor_trace << error_no << " " << error_str << std::endl;
  }

  // Called when the reactor is shutting down. The reactor is set to nullptr.
  void handle_shutdown(Reactor *reactor) override
  {
    (void)reactor;
    reactor_trace << std::endl;
  }

  // Called when removed from Reactor.
  void handle_removed(Reactor *reactor) override
  {
    (void)reactor;
    reactor_trace << std::endl;
    ::close(io_handle_);
    delete this;
  }

protected:
  char buff_[1024];
};

class Svc_HandlerFactory : public EventHandlerFactory
{
public:
  virtual ~Svc_HandlerFactory() {}

  EventHandler *create(Reactor *reactor) override
  {
    (void)reactor;
    return new Svc_Handler;
  }
};

int main(void)
{
  Reactors reactors;
  reactors.init(5);
  reactors.start();

  Acceptor acc;
  acc.listen_ipv46(2000);

  Svc_HandlerFactory svc_factory;

  AcceptorThread *accThread;
  accThread = new AcceptorThread(acc,
                                 reactors,
                                 svc_factory);
  accThread->start();

  while (true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  accThread->stop();
  delete accThread;

  reactors.stop();
  return 0;
}
