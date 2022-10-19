// gamescreen output functions

#include "../n_shared.h"
#include "../n_bff.h"
#include "g_game.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_HUD_QUEUE		5
#define MAX_HUD_ROWS		2

char* hud_queue[MAX_HUD_QUEUE];

static char** H_FormatString(char* queue_msg, game_t* hud)
{
	int mlen = strlen(queue_msg);
	for (int i = 0; i < mlen; i++) {
		arr[i] = queue_msg[i];
	}
	if (mlen <= hud->c_hud_tbox_y) {
		int arr_f[1][mlen];
		for (int i = 0; i < mlen; i++) {
			arr_f[0][i] = arr1[i];
		}
	}
	if (mlen <= hud->c_hud_tbox_x) {
		char* arr[1];
		for (int i = 0; i < mlen; i++) {
			arr[0][i] = queue_msg[i];
		}
		return arr;
	}
	else if (mlen > hud->c_hud_tbox_x) {
		char* arr[2];
		for (int i = 0; i < hud->c_hud_tbox_x; i++) {
			arr[0][i] = queue_msg[i];
		}
		for (int i = 0; i < (mlen - hud->c_hud_tbox_x); i++) {
			arr[1][i] = queue_msg[i + (mlen - hud->c_hud_tbox_x)];
		}
		return arr;
	}
	else {
#if defined(_N_DEBUG_)
		gameError(STR_TO_LONG_FOR_HUD);
#else
		return 0;
#endif
	}
}

static void H_ShiftQueue(void)
{
	for (int i = 0; i < MAX_HUD_QUEUE; i++) {
		hud_queue[i] = hud_queue[i+1];
	}
	hud_queue[MAX_HUD_QUEUE - 1] = NULL;
}

static int H_FindEmptyTBoxIndex(game_t* hud)
{
	for (short y = 0; y < hud->c_hud_tbox_y; y++) {
		if (hud->c_hud_tbox[y][0] == ' ' || NULL) {
			return y;
		}
		else {
			continue;
		}
	}
	return 0;
}

static void H_InsertStrToTBox(char** msg, game_t* hud)
{
	if (strlen(msg) > hud->c_hud_tbox_x) {
		short y = H_FindEmptyTBoxIndex(hud);
		for (int i = 0; i++) {
			if (i == hud->c_hud_tbox_x) {
				break;
			}
			else {
				hud->c_hud_tbox[y][i] = msg[0][i];
			}
		}
		for (int i = 0; i++) {
			if (i == (strlen(msg) - hud->c_hud_tbox_x)) {
				break;
			}
			else {
				hud->c_hud_tbox[y+1][i] = msg[1][i];
			}
		}
	}
	else {
		short y = H_FindEmptyTBoxIndex(hud);
		for (int i = 0; i < strlen(msg); i++) {
			hud->c_hud_tbox[y][i] = msg[0][i];
		}
	}
}

static short H_FindEmptyIndex(void)
{
	for (short i = 0; i < MAX_HUD_QUEUE; i++) {
		if (hud_queue[i] == NULL || "NULL" || " ") {
			return i;
		}
	}
	if (hud_queue[MAX_HUD_QUEUE - 1] != NULL) {
		return 0;
	}
}

void HudPrintf(const char* message, game_t* hud)
{
	short i = H_FindEmptyIndex();
	if (!i) {
		H_ShiftQueue();
		i = H_FindEmptyIndex();
		hud_queue[i] = message;
		char** msg = H_FormatString(hud_queue[i], hud);
		HudUpdateBuffer(hud, msg);
	}
	else {
		hud_queue[i] = message;
		char** msg = H_FormatString(hud_queue[i], hud);
		H_InsertStrToTBox(msg, hud);
		HudUpdateBuffer(hud, i);
	}
}

static void HudShiftTBox(game_t* hud)
{
	short len = strlen(hud_queue[0]);
	if (len > hud->c_hud_tbox_x) {
		for (short x = 0; x < hud->c_hud_tbox_x; x++) {
			if (hud->c_hud_tbox[0][x] != NULL) {
				hud->c_hud_tbox[0][x] = NULL;
			}
			if (hud->c_hud_tbox[1][x] != NULL) {
				hud->c_hud_tbox[1][x] = NULL;
			}
		}
	}
	else {
		for (short x = 0; x < hud->c_hud_tbox_x; x++) {
			if (hud->c_hud_tbox[0][x] != NULL) {
				hud->c_hud_tbox[0][x] = NULL;
			}
		}
	}
	
}

void HudUpdateBuffer(game_t* hud, char** msg)
{
	short index = H_FindEmptyTBoxIndex(hud);
	if (!index) {
		HudShiftTBox(hud);
	}
	index = H_FindEmptyTBoxIndex(hud);
	H_InsertStrToTBox(msg, hud);
	short top_y_gs = hud->bff.gs.tbox_top_y;
	short top_x_gs = hud->bff.gs.tbox_top_x;
	short tbox_y = hud->c_hud_tbox_y;
	short tbox_x = hud->c_hud_tbox_x;
	if (hud->c_hud_layer[1]) {
		for (short y = 0; y < hud->c_hud_tbox_y; y++) {
			char* tbox = (char*)malloc(hud->c_hud_tbox_x);
			strcpy(tbox, hud->c_hud_tbox[y]);
		
			// really sry for the mess here
			for(short x = hud->bff.gs.tbox_top_x, short l = 0;
				x < (hud->c_hud_tbox_x + hud->bff.gs.tbox_top_x),
				l < hud->c_hud_tbox_x; x++; l++)
			{
				hud->c_hud[y + hud->bff.gs.tbox_top_y][x] = tbox[y][l];
			}
			free(tbox);
		}
		if (hud->c_hud[top_y_gs][top_x_gs] == '#'
		&&  hud->c_hud[top_y_gs + (tbox_y + 1)][top_x_gs] == '#'
		&&  hud->c_hud[top_y_gs][top_x_gs + (tbox_x + 1)] == '#'
		&&  hud->c_hud[top_y_gs + (tbox_y - 1)][top_x_gs + (tbox_x + 1)] == '#') {
			printScreen(hud, HUD);
		}
		else {
			hud->c_hud[top_y_gs][top_x_gs] = '#';
			hud->c_hud[top_y_gs + (tbox_y + 1)][top_x_gs] = '#';
			hud->c_hud[top_y_gs][top_x_gs + (tbox_x + 1)] = '#';
			hud->c_hud[top_y_gs + (tbox_y - 1)][top_x_gs + (tbox_x + 1)] = '#';
			printSreen(hud, HUD);
		}
	}
}

void printScreen(game_t* game, int screen)
{
	int y;
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#endif
	switch (screen) {
	case HUD:
		for (y = 0; y < game->c_hud_height; y++) {
			printf("%s\n", game->c_hud[y]);
		}
		break;
	case INVENTORY:
		for (y = 0; y < game->c_inv_height; y++) {
			printf("%s\n", game->c_inv[y]);
		}
		break;
	case MAP:
		for ()
		break;
	case MENU_PAUSE:
	case MENU_TITLE:
	case MENU_MAIN:
	case MENU_CAMPAIGN:
	case MENU_SETTINGS:
		break;
	};
}