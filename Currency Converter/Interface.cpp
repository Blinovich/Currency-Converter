#include "Interface.h"


void Interface::hello() {
	std::cout << "Hello! This is a console application for viewing real cryptocurrency quotes.\n\nMade by Blinovich.";
	Sleep(3000);
	system("cls");
}

int Interface::menu() {
	std::ifstream fin("menu.txt");

	if (!fin.is_open()) return 0;

	std::string line;
	while (getline(fin, line)) {
		std::cout << line << std::endl;
	}

	fin.close();
	
	int choice = 0;
	std::cin >> choice;

	system("cls");

	return choice;
}

void Interface::responseLiveHistoricalAndList(Client client) {
	std::string mode, symbols;
	std::cout << "Do you want to see the results historical (last 365 days), live or list?\nChoice: ";
	std::cin >> mode;

	if (mode == "historical" || mode == "live") {
		if (mode == "historical") {
			std::cout << "Enter the date (last 365 days) in the format YYYY-MM-DD:";
			std::cin >> mode;
		}
		std::cout << "Enter the cryptocurrencies you are interested in in an abbreviated format (example: BTC, ETH), if this is not necessary, then write \"no\": ";
		std::cin >> symbols;

		system("cls");
		client.findResponse(mode, symbols);

	}
	else if (mode == "list") {
		system("cls");
		client.findResponse(mode);
	}
	else {
		system("cls");
		std::cout << "\nError!\n";
		return;
	}
} 
