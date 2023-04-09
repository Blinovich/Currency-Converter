#include "Client.h"

static std::string access_key = "e5035c8baeea1258c3eb4fbfc5102ca7";

void Client::getResponse() {
	for (size_t i = 0; i < request.size(); i++) {
		if (request[i] == ',') {
			std::cout << '\n';
			continue;
		}
		std::cout << request[i];
	}
}

bool Client::setAccessKey(const int num = 0) {
	if (num == 1) {
		std::cout << "You can get your access key here: https://coinlayer.com/\nEnter your access key: ";
		std::cin >> access_key;
		if (access_key.size() < 32) return false;
	}
	this->access_key = access_key;
	return true;
}

std::string Client::getAccessKey() {
	return access_key;
}


std::string Client::request = "";
std::string Client::access_key = "";
