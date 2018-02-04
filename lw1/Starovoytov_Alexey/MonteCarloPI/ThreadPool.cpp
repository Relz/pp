#include "ThreadPool.h"

void ThreadPool::Add(LPTHREAD_START_ROUTINE threadFunction, LPVOID data)
{
	m_threadHandles.emplace_back(CreateThread(NULL, NULL, threadFunction, data, NULL, NULL));
}

void ThreadPool::Close()
{
	for (HANDLE const& threadHandle : m_threadHandles)
	{
		CloseHandle(threadHandle);
	}
}

void ThreadPool::Wait()
{
	WaitForMultipleObjects(m_threadHandles.size(), m_threadHandles.data(), TRUE, INFINITE);
}
