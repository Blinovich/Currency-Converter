#pragma once

#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>
#include <iostream>

const static std::string MAIN_API = "api.coinlayer.com";
const static std::string API_ARGUMENTS = "/live?access_key=";
std::string access_key = "e5035c8baeea1258c3eb4fbfc5102ca7";

namespace http = boost::beast::http; 

class Client {
public:
	static std::string findResponse() { // сделать наследуемым
		boost::asio::io_context io;
		boost::asio::ip::tcp::resolver resolver(io);
		boost::asio::ip::tcp::socket socket(io);

		boost::asio::connect(socket, resolver.resolve(MAIN_API, "80"));
		http::request<http::string_body> req(http::verb::get, API_ARGUMENTS + getAccessKey(), 11);
		

		req.set(http::field::host, MAIN_API);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(socket, req);

		std::string response;
		{
			boost::beast::flat_buffer buffer;
			http::response<http::dynamic_body> res;
			http::read(socket, buffer, res);
			response = boost::beast::buffers_to_string(res.body().data());
		}

		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		request = response;
		
		return "Done!";
	}
	void getResponse();
	bool setAccessKey();
	

private:
	static std::string getAccessKey();
	static std::string request;
	static std::string access_key;
};

