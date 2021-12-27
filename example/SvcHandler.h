#ifndef SIMPLE_REACTOR_REACTOR_SVCHANDLER_H_
#define SIMPLE_REACTOR_REACTOR_SVCHANDLER_H_

#include <acceptor/AcceptorThread.h>
#include <reactor/ReactorThread.h>
#include <reactor/trace.h>

#include <string.h>

namespace reactor
{
    // client handler
    class Svc_Handler : public EventHandler
    {
    protected:
        virtual ~Svc_Handler();
        // When a new connection is created and registered with the reactor.
        void register_handler(Reactor *reactor, const io_handle_t &io_handle) override;

        // Callback from the reactor when data are available
        void handle_input(Reactor *reactor) override;

        // Called when writing is possible.
        void handle_output(Reactor *reactor) override;

        // Callback from the Reactor when the client is disconnected.
        void handle_close(Reactor *reactor) override;

        // When Reactor's set_timeout(msec) is called,
        // Reactor calls handle_timeout() after the timeout.
        // set_timeout is one-time. If you want to call handle_timeout repeatedly,
        // you must call Reactor::set_timeout(msec) each time.
        void handle_timeout(Reactor *reactor) override;

        // Called on error. The error is set to the standard errno.
        void handle_error(Reactor *reactor, const int &error_no = 0, const std::string &error_str = "") override;

        // Called when the reactor is shutting down. The reactor is set to nullptr.
        void handle_shutdown(Reactor *reactor) override;

        // Called when removed from Reactor.
        void handle_removed(Reactor *reactor) override;

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

} // end namespace reactor

#endif /* OPEN_REACTOR_DEFINEDTYPE_H */
