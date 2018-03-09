#pragma once
#include <Windows.h>
#include <vector>

class ThreadCollection
{
public:
	void Add(LPTHREAD_START_ROUTINE threadFunction, LPVOID data);
	void CloseAll();
	void Wait();

private:
	std::vector<HANDLE> m_threadHandles;
};
