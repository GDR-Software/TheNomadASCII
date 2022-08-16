#ifndef _CAMPAIGN_H_
#define _CAMPAIGN_H_

class Campaign
{
private:
	float extra_mult = 0.1f;
	float noob_mult = 1.3f; // can ya shoot straight lad? or are ya fuckin' blind?
	float recruit_mult = 3.7f; // baby steps
	float merc_mult = 6.19f; // medium shit
	float nomad_mult = 10.5f; // game's pretty hard
	float blackdeath_mult = 20.12f; // they're asking for it
public:
	float M_spawnMultiplier();
	float M_statMultiplier();
	float P_statMultiplier();
	
	float I_spawnMultiplier();
	float I_statMultiplier();
	
	float L_spawnMultiplier();
};

#endif
