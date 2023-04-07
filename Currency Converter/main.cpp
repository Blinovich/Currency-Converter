#include <iostream>
#include "Client.h"
#include "Interface.h"

std::string access_key = "e5035c8baeea1258c3eb4fbfc5102ca7";

int main() {


	Client client;
	client.setAccessKey(access_key);
	client.findResponse();
	client.getResponse();
	
	return 0;
}