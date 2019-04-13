#include "server/server.h"
#include "boost/asio.hpp"

int main()
{
	try
	{
		boost::asio::io_context io_context;
		Server s = Server(io_context, 6299);

		io_context.run();
	}
	catch (boost::system::system_error & ec)
	{
		std::cout << ec.what() << std::endl;
	}

	return 0;
}