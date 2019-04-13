#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>


class Session : public std::enable_shared_from_this<Session>
{
private:
	boost::asio::ip::tcp::socket socket_;
	
	std::string address_;

	bool first_run = true;

	char buffer_data_[1024];
	std::vector<char> time_buffer_;

public:
	Session(boost::asio::io_context& io_context);
	~Session();

	boost::asio::ip::tcp::socket& get_socket();

	void start();
	void write_message();
	void handle_read(const boost::system::error_code& ec, std::size_t bytes_transferred);



};