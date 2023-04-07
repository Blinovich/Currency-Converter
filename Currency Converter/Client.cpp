#include "Client.h"

void Client::getResponse() {
	for (size_t i = 0; i < request.size(); i++) {
		if (request[i] == ',') {
			std::cout << '\n';
			continue;
		}
		std::cout << request[i];
	}
}

bool Client::setAccessKey(const std::string access_key) {
	if (access_key.size() < 32) return false;
	this->access_key = access_key;
	return true;
}

std::string Client::getAccessKey() {
	return access_key;
}


std::string Client::request = "";
std::string Client::access_key = "";
