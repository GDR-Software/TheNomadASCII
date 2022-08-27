#incldue <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#include "game.h"
#include "nomaddef.h"

std::vector<std::vector<std::string>> hudvec;
char HUD[26][75];

// from geeksforgeeks.com
char* convertInttoChar(int N)
{
 
    // Count digits in number N
    int m = N;
    int digit = 0;
    while (m) {
 
        // Increment number of digits
        digit++;
 
        // Truncate the last
        // digit from the number
        m /= 10;
    }
 
    // Declare char array for result
    char* arr;
 
    // Declare duplicate char array
    char arr1[digit];
 
    // Memory allocation of array
    arr = (char*)malloc(digit);
 
    // Separating integer into digits and
    // accommodate it to character array
    int index = 0;
    while (N) {
 
        // Separate last digit from
        // the number and add ASCII
        // value of character '0' is 48
        arr1[++index] = N % 10 + '0';
 
        // Truncate the last
        // digit from the number
        N /= 10;
    }
 
    // Reverse the array for result
    int i;
    for (i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }
 
    // Char array truncate by null
    arr[i] = '\0';
 
    // Return char array
    return (char*)arr;
}

static void insertNameHUD()
{
	playr = std::make_unique<Playr>();
	if (playr->playr_name.length() > )
}

// this only triggers once when the game is begun
void Game::makeHUD()
{
	std::fstream hudfile;
	hudfile.open("../File/GameScreens/HUD.txt", std::ios::in);
	std::string line;
	while (std::getline(hudfile, line))
	{
		hudvec.push_back(line);
	};
	playr = std::make_unique<Playr>();
	for (size_t y = 0; y < 26; y++)
	{
		for (size_t x = 0; x < 75; x++)
		{
			if (hudvec[y][x] == 'N' && hudvec[y][x+1] == 'A')
			{
				insertNameHUD();
			}
			else {
				HUD[]
			}
		}
	}
	char* hp = convertInttoChar(playr->playr_hp);
	char* aq = convertInttoChar(playr->playr_aq);
	char* coin = convertInttoChar(playr->playr_coin);
	if (playr->playr_hp < 10)
	{
		HUD[19][12] = hp[0];
	}
	else if (playr->playr_hp > 9)
	{
		HUD[19][12] = hp[0];
		HUD[19][11] = hp[1];
	}
	else { // assuming the player's health is == to 100
		HUD[19][12] = '1';
		HUD[19][11] = '0';
		HUD[19][10] = '0';
	}
	// there will be things in the future versions where a player can have greater than 100 health, but not for now
	
	if (playr->playr_aq < 10)
	{
		HUD[20][11] = aq[0];
	}
	else if (playr->playr_aq > 9)
	{
		HUD[20][11] = aq[1];
		HUD[20][10] = aq[0];
	}
	if (playr->playr_coin < 10)
	{
		HUD[21][11] = coin[0];
	}
	else if (playr->playr_coin > 9)
	{
		HUD[21][11] = coin[1];
		HUD[21][10] = coin[0];
	}
	else if (playr->playr_coin > 99)
	{
		HUD[21][11] = coin[2];
		HUD[21][10] = coin[1];
		HUD[21][9] = coin[0];
	}
	else {
		HUD[21][11] = coin[3];
		HUD[21][10] = coin[2];
		HUD[21][9] = coin[1];
		HUD[21][8] = coin[0];
	}
}


void Game::updateHUD()
{
	
}