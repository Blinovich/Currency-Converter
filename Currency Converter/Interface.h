#pragma once
#include <Windows.h>
#include <fstream>
#include "Client.h"


class Interface {
public:
	void hello();
	int menu();
	void responseLiveHistoricalAndList(Client client);
};

