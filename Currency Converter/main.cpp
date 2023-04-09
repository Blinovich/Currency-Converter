// All features provided here are available to all (All Plans). There is no money to upgrade the plan (

#include <iostream>
#include <string>
#include "Client.h"
#include "Interface.h"

// Спросить у Вадима про объединение всех кейсов в один, но с выбором аргумента. Будет ли это усложнять читаемость кода?

int main() {
	Interface i;
	i.hello();

	Client client;
	client.setAccessKey(0);

	int numChoice = i.menu();
	std::string temp;
	std::string mode;
	switch (numChoice) {
	case 1:
		client.setAccessKey(numChoice);
		break;
	
	case 2:
		client.findResponse("live");
		break;
	
	case 3:
		std::cout << "Do you want to see the output in live or historical mode?";
		std::cin >> mode;
		std::cout << "Enter the cryptocurrencies you are interested in in an abbreviated format (BTC, ETH): ";
		std::cin >> temp;

		client.findResponse(mode, temp);
		
		break;

	case 4:
		std::cout << "Enter a specific day according to the template YYYY-MM-DD: ";
		std::cin >> temp;

		client.findResponse(temp);
		
		break;

	case 5:
		client.findResponse("list");
		break;

	case 0:
		std::cout << "Goodbye!";
		return 0;
	};
	client.getResponse();

	return 0;
}