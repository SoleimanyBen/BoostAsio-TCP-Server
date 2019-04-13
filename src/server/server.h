#pragma once
#include <boost/asio.hpp>
#include "session.h"
#include "session_pool.h"

typedef std::shared_ptr<Session> session_ptr;

class Server
{
private:
	boost::asio::io_context& io_context_;
	boost::asio::ip::tcp::acceptor acceptor_;

	std::shared_ptr<Session> session_;
	std::shared_ptr<SessionPool> session_pool_;

public:
	Server(boost::asio::io_context& io_context, short port);

	void start_accepting();
	void handle_accept(const boost::system::error_code& ec);
	void handle_shutdown();
};
