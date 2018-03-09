#include "GitServer.h"

void GitServer::ObserveTask(Task * task)
{
	m_tasks.emplace(task);
	task->DoOnDoneChange(
		[this, task](bool isDone) {
			if (isDone)
			{
				m_doneTasks.emplace(task);
			}
			else
			{
				m_doneTasks.erase(task);
			}
		},
		true);
	task->DoOnApprovedChange([this, task](bool isApproved) {
		if (isApproved)
		{
			m_approvedTasks.emplace(task);
		}
		else
		{
			m_approvedTasks.erase(task);
		}
	});
}

Task * GitServer::GetWaitingForReviewTaskExcept(Task * exceptTask) const
{
	for (auto & it = m_doneTasks.begin(); it != m_doneTasks.end(); ++it)
	{
		if (*it != exceptTask && m_approvedTasks.find(*it) == m_approvedTasks.end())
		{
			return *it;
		}
	}
	return nullptr;
}
