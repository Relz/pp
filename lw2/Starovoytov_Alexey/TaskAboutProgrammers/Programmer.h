#pragma once

#include "GitServer.h"
#include "Logger.h"
#include "RandomHelper.h"
#include "Task.h"
#include "ThreadCollection.h"
#include <iostream>
#include <windows.h>

struct ProgrammerActivityData
{
	Task * task;
	GitServer * gitServer;
};

class Programmer
{
public:
	Programmer(unsigned int id, ThreadCollection * threadCollection, GitServer * gitServer);
	unsigned int GetId() const;
	bool IsSleeping() const;
	Task * GetTask() const;

private:
	unsigned int m_id;
	Task * m_task;

	static DWORD WINAPI Activity(LPVOID CONST data);
	static bool HasProgrammerCompletedTask();
	static bool HasProgrammerApprovedPullRequest();
};
