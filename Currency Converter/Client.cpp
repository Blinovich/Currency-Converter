#include "Client.h"

static std::string default_access_key = "e5035c8baeea1258c3eb4fbfc5102ca7";

void Client::getResponse() {
	for (size_t i = 0; i < request.size(); i++) {
		if (request[i] == ',') {
			std::cout << '\n';
			continue;
		}
		std::cout << request[i];
	}
	std::cout << "\n\n";
	system("pause"); // only for Windows
	system("cls");
}

bool Client::setAccessKey(const int num = 0) {
	if (num == 1) {
		std::string temp_access_key;
		std::cout << "You can get your access key here: https://coinlayer.com/\nEnter your access key: ";
		std::cin >> temp_access_key;
		 
		if (temp_access_key.size() < 32) {
			std::cout << "Error! The access key is too small.";
			system("pause");
			return false;
		}
		this->access_key = temp_access_key;
	}
	else {
		this->access_key = default_access_key;
	}
	
	return true;
}

std::string Client::getAccessKey() {
	return access_key;
}


std::string Client::request = "";
std::string Client::access_key = "";
