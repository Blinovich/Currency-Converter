#include "Interface.h"


void Interface::hello() {
	std::cout << "Hello! This is This is a console application for viewing real cryptocurrency quotes.\n\nMade by Blinovich.";
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
