#pragma once
#include <Windows.h>
#include <vector>

using namespace std;

class ThreadHelper
{
public:
	static HANDLE CreateSimpleThread(LPTHREAD_START_ROUTINE threadFunction, LPVOID data);
	static void CloseThreads(vector<HANDLE> const& threadHandles);
};

