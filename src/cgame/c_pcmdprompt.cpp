using namespace Campaign;

void Playr::mod_keybind()
{
	
}

void Playr::cmd_prompt(void)
{
#ifdef _WIN32
	c = _getch();
	switch ((int)c) {
	case keyBindings[keyShoot][1]:
								   break;
	case keyBindings[keyMove_n][1]:
									break;
	case keyBindings[keyMove_w][1]:
									break;
	case keyBindings[keyMove_s][1]:
									break;
	case keyBindings[keyMove_e][1]:
									break;
	
	case keyBindings[keyAxis_l][1]: move_axis(i);
									break;
	case keyBindings[keyAxis_r][1]: move_axis(i);
					  				break;
	
	case keyBindings[keyShowWpns][1]: if (showing_wpns) {showing_wpns = false;}
									  else {showing_wpns = true;}
									  break;
	case keyBindings[keyFlashlight][1]: if (flash) {flash = false;}
										else {flash = true;}
										break;
	case keyBindings[keyJump][1]: 
								  break;
	case keyBindings[keyMelee][1]:
								   break;
	case keyBindings[keyInteract][1]:
									  break;
	case keyBindings[keyCrouch][1]:
									break;
	case keyBindings[keyThrowGrenade][1]:
										  break;
	};
#elif __linux__
	system("stty raw");
	int i;
	std::cin >> i;
	switch (i) {
	case keyBindings[keyShoot][1]:
								   break;
	case keyBindings[keyMove_n][1]: pz -= (playr_speed + 0.25f);
									break;
	case keyBindings[keyMove_w][1]: px -= (playr_speed + 0.25f);
									break;
	case keyBindings[keyMove_s][1]: pz += (playr_speed + 0.25f);
									break;
	case keyBindings[keyMove_e][1]: px += (playr_speed + 0.25f);
									break;
	
	case keyBindings[keyAxis_l][1]: move_axis(i);
									break;
	case keyBindings[keyAxis_r][1]: move_axis(i);
					  				break;
	
	case keyBindings[keyShowWpns][1]: if (showing_wpns) {showing_wpns = false;}
									  else {showing_wpns = true;} 
									  break;
	
	case keyBindings[keyFlashlight][1]:
										break;
	case keyBindings[keyJump][1]: playr_jump();
								  break;
	case keyBindings[keyMelee][1]: // TODO: write combat code here
								   break;
	case keyBindings[keyInteract][1]: // TODO: write interaction function here
									  break;
	case keyBindings[keyCrouch][1]: py -= 1.5f;
									break;
	case keyBindings[keyThrowGrenade][1]:
										  break;
	case keyBindings[keyEscape][1]: escapeValue();
	};
#else
#ifdef NOMAD_VM
	int i;
	std::cin >> i;
	switch (i) {
	case keyBindings[keyShoot][1]:
								   break;
	case keyBindings[keyMove_n][1]:
									break;
	case keyBindings[keyMove_w][1]:
									break;
	case keyBindings[keyMove_s][1]:
									break;
	case keyBindings[keyMove_e][1]:
									break;
	
	case keyBindings[keyAxis_l][1]: move_axis(i);
									break;
	case keyBindings[keyAxis_r][1]: move_axis(i);
					  				break;
	
	case keyBindings[keyShowWpns][1]:
									  break;
	
	case keyBindings[keyFlashlight][1]:
										break;
	case keyBindings[keyJump][1]:
								  break;
	case keyBindings[keyMelee][1]:
								   break;
	case keyBindings[keyInteract][1]:
									  break;
	case keyBindings[keyCrouch][1]:
									break;
	case keyBindings[keyThrowGrenade][1]:
										  break;
	};
#endif
}