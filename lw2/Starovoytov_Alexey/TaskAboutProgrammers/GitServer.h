#pragma once

#include "Task.h"
#include <unordered_set>

class GitServer
{
public:
	void ObserveTask(Task * task);
	Task * GetDoneTask() const;

private:
	std::unordered_set<Task *> m_tasks;
	std::unordered_set<Task *> m_doneTasks;
};
