#include <vector>

#include "c_campaign.h"
#include "c_data.h"

using namespace Campaign;

std::vector<std::string> saves;

std::vector<std::string> p_buff1; // playr buffer
std::vector<int> p_buff2;
std::vector<float> p_buff3;

std::vector<std::string> e_buff1; // mob buffer
std::vector<int> e_buff2;
std::vector<float> e_buff3;

std::vector<std::string> l_buff1; // location/map buffer
std::vector<int> l_buff2;

std::string saveName;

inline bool Data::fileExists (const std::string& name)
{
	struct stat buff;
	return (stat (name.c_str(), &buff) == 0); 
}

size_t i = 0;

playr = std::make_unique<Playr>();
mob = std::make_unique<Mob>();

void Data::listSave()
{
	
}

void Data::makeSave(const int svnum, const std::string& svname)
{
	saveSlots[svnum] = svname;
	std::ofstream fileWrite_pbuff1("../Files/gamedata/usrdata/sv" + svnum + "/p_str.txt");
	std::ofstream fileWrite_pbuff2("../Files/gamedata/usrdata/sv" + svnum + "/p_nums.txt");
	std::ofstream fileWrite_pbuff3("../Files/gamedata/usrdata/sv" + svnum + "/p_floats.txt");
	
	std::ofstream fileWrite_ebuff1("../Files/gamedata/usrdata/sv" + svnum + "/e_active_str.txt");
	std::ofstream fileWrite_ebuff2("../Files/gamedata/usrdata/sv" + svnum + "/e_active_nums.txt");
	std::ofstream fileWrite_ebuff3("../Files/gamedata/usrdata/sv" + svnum + "/e_active_floats.txt");
	
	std::ofstream fileWrite_lbuff1("../Files/gamedata/usrdata/sv" + svnum + "/l_str.txt");
	std::ofstream fileWrite_lbuff2("../Files/gamedata/usrdata/sv" + svnum + "/l_nums.txt");
	
	fileWrite_pbuff1 << playr->playr_guild << "\n";
	fileWrite_pbuff1 << playr->playr_location << "\n";
	fileWrite_pbuff1 << playr->wpn_in_hand << "\n";
	for (i = 0; i < 8; i++)
	{
		fileWrite_pbuff1 << playr->P_wpn[i] << "\n";
	}
	int pAlive = (int)playr->playr_alive;
	fileWrite_pbuff2 << playr->playr_hp << "\n";
	fileWrite_pbuff2 << playr->playr_coin << "\n";
	fileWrite_pbuff2 << pAlive << "\n";
	fileWrite_pbuff2 << playr->map_active << "\n";
	fileWrite_pbuff2 << playr->wpn_in_hand_reserves << "\n";
	fileWrite_pbuff2 << playr->wpn_in_hand_mag << "\n";
	
	fileWrite_pbuff3 << playr->py << "\n";
	fileWrite_pbuff3 << playr->px << "\n";
	fileWrite_pbuff3 << playr->playr_aq << "\n";
	fileWrite_pbuff3 << playr->playr_speed << "\n";
	fileWrite_pbuff3 << playr->playr_stat_mult << "\n";
	
	for (i = 0; i < m_ActiveNames.size(); i++)
	{
	
	}
	for ()
	fileWrite_ebuff1 << mob-> << "\n";
}

void Data::updateSave(const int svnum)
{
	std
}

void Data::readSave(const std::string filename)
{
	std::ifstream fileRead("../Files/gamedata/sv_" + filename + ".txt");
	int c_line = 0;
	while (!fileRead.eof())
	{
		c_line++;
		if (c_line == 1) {sv_strings.push_back();}
	};
}

void Data::wipeSave()
{

}

void Data::renameSave()
{

}