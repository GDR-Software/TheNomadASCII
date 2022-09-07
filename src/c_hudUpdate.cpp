#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#include "c_game.h"
#include "c_item.h"
#include "../nomaddef.h"
#include "c_playr.h"

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

void Game::updateHUD()
{
	playr = std::make_unique<Playr>():
	item = std::make_unique<Item>();
	size_t y = 0;
	size_t x = 0;
	if (playr->playr_alive)
	{
		std::fstream hudfile;
		std::string line;
		for (size_t i = 0; i < item->wpn_ls.size(); i++)
		{
			if (item->wpn_ls[i] == playr->wpn_in_hand)
			{
				if (playr->wpn_in_hand_fr == FR_SINGLE)
				{
					hudfile.open("../Files/GameScreens/HUDs/HUD" + playr->wpn_in_hand + "-" + playr->wpn_in_hand_ammo + "-" + playr->wpn_in_hand_reserves + "-sfr.txt", std::ios::in);
					for (y = 0; y < HUDMAP_MAX_Y; y++)
					{
						for (x = 0; x < HUDMAP_MAX_X; x++)
						{
							hudfile >> HUD[y][x];
						}
					}
				}
				else if (playr->wpn_in_hand_fr == FR_BURST_2)
				{
					hudfile.open("../Files/GameScreens/HUDs/HUD" + playr->wpn_in_hand + "-" + playr->wpn_in_hand_ammo + "-" + playr->wpn_in_hand_reserves + "-bfr2.txt", std::ios::in);
					for (y = 0; y < HUDMAP_MAX_Y; y++)
					{
						for (x = 0; x < HUDMAP_MAX_X; x++)
						{
							hudfile >> HUD[y][x];
						}
					}
				}
				else if (playr->wpn_in_hand_fr == FR_BURST_3)
				{
					hudfile.open("../Files/GameScreens/HUDs/HUD" + playr->wpn_in_hand + "-" + playr->wpn_in_hand_ammo + "-" + playr->wpn_in_hand_reserves + "-bfr3.txt", std::ios::in);
					for (y = 0; y < HUDMAP_MAX_Y; y++)
					{
						for (x = 0; x < HUDMAP_MAX_X; x++)
						{
							hudfile >> HUD[y][x];
						}
					}

				}
				else if (playr->wpn_in_hand_fr == FR_BURST_4)
				{
					hudfile.open("../Files/GameScreens/HUDs/HUD" + playr->wpn_in_hand + "-" + playr->wpn_in_hand_ammo + "-" + playr->wpn_in_hand_reserves + "-bfr4.txt", std::ios::in);
					for (y = 0; y < HUDMAP_MAX_Y; y++)
					{
						for (x = 0; x < HUDMAP_MAX_X; x++)
						{
							hudfile >> HUD[y][x];
						}
					}
				}
				if (playr->wpn_in_hand_fr == FR_AUTO)
				{
					hudfile.open("../Files/GameScreens/HUDs/HUD" + playr->wpn_in_hand + "-" + playr->wpn_in_hand_ammo + "-" + playr->wpn_in_hand_reserves + "-afr.txt", std::ios::in);
					for (y = 0; y < HUDMAP_MAX_Y; y++)
					{
						for (x = 0; x < HUDMAP_MAX_X; x++)
						{
							hudfile >> HUD[y][x];
						}
					}
				}
			}
		}
	}
	else {
		std::fstream hudfile;
		std::string line;
		hudfile.open("../Files/GameScreens/HUDs/HUDdead.txt", std::ios::in);
		for (y = 0; y < HUDMAP_MAX_Y; y++)
		{
			for (x = 0; x < HUDMAP_MAX_X; x++)
			{
				hudfile >> HUD[y][x];
			}
		}
	}
}