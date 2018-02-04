#pragma once
#include <Windows.h>
#include <vector>

using namespace std;

class ThreadPool
{
public:
	void Add(LPTHREAD_START_ROUTINE threadFunction, LPVOID data);
	void Close();
	void Wait();

private:
	vector<HANDLE> m_threadHandles;
};

