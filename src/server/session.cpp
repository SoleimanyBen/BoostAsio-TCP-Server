#include "session.h"
#include <chrono>


Session::Session(boost::asio::io_context& io_context) : socket_(io_context), buffer_data_()
{
}

Session::~Session()
{
	std::cout << "Session terminated" << std::endl;
}

boost::asio::ip::tcp::socket& Session::get_socket()
{
	return socket_;
}

void Session::start()
{
	// This is done seperately from the constructor because the session object is created before the socket can be created
	// TODO: Look for a better way?
	if (first_run)
	{
		write_message();

		first_run = false;
	}

	auto self = shared_from_this();


	socket_.async_read_some(boost::asio::buffer(&buffer_data_, 1024),
		boost::bind(&Session::handle_read, self, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Session::write_message()
{
	std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(time);
	std::string time_string = std::ctime(&t);

	time_buffer_.resize(time_string.size());

	for (int i = 0; i < time_buffer_.size(); ++i)
	{
		time_buffer_[i] = time_string[i];
	}

	auto self = shared_from_this();

	socket_.async_write_some(boost::asio::buffer(&time_buffer_, sizeof(time_buffer_)),
		[this, self](const boost::system::error_code & ec, std::size_t bytes_transferred)
		{
			std::cout << "Current time has been sent to client" << std::endl;
		});
}

void Session::handle_read(const boost::system::error_code& ec, std::size_t bytes_transferred)
{
	if (!ec)
	{
		std::cout << "Bytes: " << bytes_transferred << std::endl;
		buffer_data_[bytes_transferred] = '\0';

		std::cout << "Message: " << buffer_data_ << std::endl;

		start();
	}
}



