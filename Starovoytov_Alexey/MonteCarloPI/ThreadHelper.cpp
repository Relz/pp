#include "ThreadHelper.h"

HANDLE ThreadHelper::CreateSimpleThread(LPTHREAD_START_ROUTINE threadFunction, LPVOID data)
{
	return CreateThread(NULL, NULL, threadFunction, data, NULL, NULL);
}

void ThreadHelper::CloseThreads(vector<HANDLE> const & threadHandles)
{
	for (HANDLE const& threadHandle : threadHandles)
	{
		CloseHandle(threadHandle);
	}
}
