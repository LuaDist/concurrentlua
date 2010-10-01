#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#endif

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

/*
 * Returns the time elapsed since the epoch in milliseconds.
 */
static int
cltime_time(lua_State *L)
{
#ifdef _WIN32
	SYSTEMTIME st, est;
	FILETIME ft, eft;
	ULARGE_INTEGER i, ei;
	
	GetLocalTime(&st);
	SystemTimeToFileTime(&st, &ft);
	i.HighPart = ft.dwHighDateTime;
	i.LowPart = ft.dwLowDateTime;

	est.wYear = 1970;
	est.wMonth = 1;
	est.wDay = 1;
	est.wHour = 0;
	est.wMinute = 0;
	est.wSecond = 0;
	est.wMilliseconds = 0;
	SystemTimeToFileTime(&est, &eft);
	ei.HighPart = eft.dwHighDateTime;
	ei.LowPart = eft.dwLowDateTime;

	lua_pushnumber(L, ((i.QuadPart - ei.QuadPart) / 10000));
#else
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
		return 0;

	lua_pushnumber(L, (unsigned long long int)(tv.tv_sec) * 1000 +
	    (unsigned long long int)(tv.tv_usec) / 1000);
#endif
	return 1;
}

/*
 * Delays for the specified amount of time in milliseconds.
 */
static int
cltime_sleep(lua_State *L)
{

#ifdef _WIN32
	Sleep((DWORD)(lua_tonumber(L, 1)));
#else
	usleep((useconds_t)(lua_tonumber(L, 1) * 1000));
#endif

	lua_pop(L, 1);

	return 0;
}

/* The cltime library. */
static const luaL_reg lib[] = {
	{ "time", cltime_time },
	{ "sleep", cltime_sleep },
	{ NULL, NULL }
};

/*
 * Opens the cltime library.
 */
LUALIB_API int
luaopen_cltime(lua_State *lua)
{

	luaL_openlib(lua, "cltime", lib, 0);

	return 1;
}
