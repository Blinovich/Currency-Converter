// All features provided here are available to all (All Plans). There is no money to upgrade the plan (
// https://coinlayer.com/

#include <iostream>
#include <string>
#include "Client.h"
#include "Interface.h"


int main() {
	Interface i;
	i.hello();

	Client client;
	client.setAccessKey(0);

	while (true) {
		system("cls");

		int numChoice = i.menu();
		switch (numChoice) {
		case 1:
			client.setAccessKey(numChoice);
			break;

		case 2:
			i.responseLiveHistoricalAndList(client);
			client.getResponse();
			break;

		case 0:
			std::cout << "Goodbye!";
			return 0;
		};
	}
}