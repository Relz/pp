#pragma once

#include "Task.h"
#include <unordered_set>

class GitServer
{
public:
	void ObserveTask(Task * task);
	Task * GetWaitingForReviewTaskExcept(Task * exceptTask) const;

private:
	std::unordered_set<Task *> m_tasks;
	std::unordered_set<Task *> m_doneTasks;
	std::unordered_set<Task *> m_approvedTasks;
};
