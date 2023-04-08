#include <iostream>
#include "Client.h"
#include "Interface.h"


int main() {
	Interface i;
	i.hello();
	
	Client client;
	
	switch (i.menu()) {
	case 1:
		client.setAccessKey(access_key);
		break;
	case 2:
		
		//client.findResponse();
		//client.getResponse();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 0:

		break;
	};

	return 0;
}