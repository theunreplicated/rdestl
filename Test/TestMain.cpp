#include <UnitTest++/src/UnitTest++.h>
#include "core/Console.h"

#define SPEED_TEST	1

void RunSpeedTests();

#if RDE_DEBUG
	long& g_BreakOnAlloc (_crtBreakAlloc);
#endif


int __cdecl main(int, char const *[])
{
	int flags = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	flags |= (flags & 0x0000FFFF) | _CRTDBG_CHECK_ALWAYS_DF;
	_CrtSetDbgFlag(flags);

#if SPEED_TEST
	void Map_SpeedTest();
	Map_SpeedTest();
#endif

    if (UnitTest::RunAllTests() != 0)
		return 1;

#if SPEED_TEST
	RunSpeedTests();
#endif

	_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);

	// Enable leak report if debugger attached
    flags |= _CRTDBG_LEAK_CHECK_DF;
	// Set the new bits
	_CrtSetDbgFlag(flags);

	return 0;
}
