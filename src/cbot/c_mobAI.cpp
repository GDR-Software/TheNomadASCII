#include <ctime>
#include <cmath>
#include <vector>

#include "nomaddef.h"

using namespace Campaign;

mob = std::make_unique<Mob>();

srand(time(NULL));

std::vector

// higher the required, less a chance of moving. You get the gist
float mob_movePR[mob->NUMMOBS][mob->NUMMOBS][mob->NUMMOBS] = { // pre-requisites
	{
	
	},
};

float mob_speed[mob->NUMMOBS] = {
	
};

// first number is moral if commander is present
// seconds number is moral without commander
int mob_moral[mob->NUMMOBS][mob->NUMMOBS] = {
	{
	
	},
};

void Mob::mob_see_playr(void)
{
	
}

void Mob::pre_atk_ID(int id)
{
	for (size_t i = 0; i < m_ActiveID.size(); i++)
	{
		if (m_ActiveID[i] == id)
		{
			
		}
	}
}

// checks if player is in range of mob attack
void Mob::M_atkInRange()
{
	
}

// sand golem attacks

// sandwurm attacks
void Mob::A_WurmSlap()
{
}
