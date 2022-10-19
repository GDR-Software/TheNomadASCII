#include "n_shared.h"

#include "g_playr.h"

static void P_Move(playr_t* playr, uint16_t dir)
{
	switch (dir) {
	case D_NORTH:
		if (playr->)
		break;
	case D_WEST:
		
	case D_SOUTH:
		
	case D_EAST:
#ifdef _N_DEBUG_
	default:
		gameError(UNKNOWN_OR_INVALID_DIR);
		break;
#else
	default:
		break;
#endif
	};
}

static void P_AttackMelee(playr_t*)
{

}

static void P_ChangeDir(playr_t* playr, uint8_t newdir)
{
	
}

void P_processInput(playr_t* playr)
{
	switch (c) { // if certain key is pressed
	case kb_binds[playr->kb_binds.kbMove_n + 2]:
		P_Move(playr, D_NORTH);
		break;
	case kb_binds[playr->kb_binds.kbMove_w + 2]:
		P_Move(playr, D_WEST);
		break;
	case kb_binds[playr->kb_binds.kbMove_s + 2]:
		P_Move(playr, D_SOUTH);
		break;
	case kb_binds[playr->kb_binds.kbMove_e + 2]:
		P_Move(playr, D_EAST);
		break;
	//case kb_binds[playr->kb_binds.kbThrowGrenade + 2]:
	//	G_Projectile();
	//	break;
//	case kb_binds[playr->kb_binds.kbCrouch + 2]:
//		playr->height;
//		break;
	case kb_binds[playr->kb_binds.kbShowWpns + 2]:
		P_DisplayString(P_wpns);
		break;
	case kb_binds[playr->kb_binds.kbRun + 2]:
	case kb_binds[playr->kb_binds.kbSlide + 2]:
	case kb_binds[playr->kb_binds.kbDash + 2]:
	case kb_binds[playr->kb_binds.kbReload + 2]:
	case kb_binds[playr->kb_binds.kbTurn_l + 2]:
	case kb_binds[playr->kb_binds.kbTurn_r + 2]:
	case kb_binds[playr->kb_binds.kbOpenChat + 2]:
#ifdef _N_DEBUG_
	case kb_binds[playr->kb_binds.kbOpenCMD + 2]:
#endif
	case kb_binds[playr->kb_binds.kbInteract + 2]:
	case kb_binds[playr->kb_binds.kbJump + 2]:
	case kb_binds[playr->kb_binds.kbSaySomething + 2]:
	case kb_binds[playr->kb_binds.kbSwimUp + 2]:
	case kb_binds[playr->kb_binds.kbSwimDown + 2]:
	case kb_binds[playr->kb_binds.kbFlashyKill + 2]:
	case kb_binds[playr->kb_binds.kbSS_left + 2]: // switch gs to the left
	case kb_binds[playr->kb_binds.kbSS_right + 2]: // switch gs to the right
	case kb_binds[playr->kb_binds.kbOpenConsole + 2]: // this can be used to access cheats
	default:
		break;
	};
}