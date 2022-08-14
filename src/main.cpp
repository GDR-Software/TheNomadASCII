#include <iostream>

#include "game.h"

int main()
{
	char d;
	std::cout << R"(
	'The Nomad' ASCII/Text-Based Roleplaying Game
	Written In C/C++ By SIGAAM
	)";
	std::cout << "Continue? [y/n]> "; std::cin >> d;
	if (d == 'y')
	{
		Game entry;
		entry.entry_point();
	}
	else {
		system("pause");
	}
}