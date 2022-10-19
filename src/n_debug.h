#ifndef _N_DEBUG_
#define _N_DEBUG_

#ifdef (NTESTBUILD || NDEBUG && NOMADMAIN)
#define DEVMODE
#endif

#define CANNOT_RANDOM_SPAWN_ENTITY				"cannot spawn entity in random location"
#define MOB_DOESNT_EXIST						"attempting to spawn a mob that doesn't exist"
#define UNKNOWN_OR_INVALID_DIR					"unknown or invalid entity direction"
#define VAR_ISNT
#define INVALID_DIFFICULTY						"game difficulty is invalid var"

#define gameError(x) \
{ \
	printf("ERROR: %s\n", x); \
	return EXIT_FAILURE; \
}

//#define consoleError(x, x)				printf("%s %s", x, x)

#endif
