#include "GitServer.h"

void GitServer::ObserveTask(Task * task)
{
	m_tasks.emplace(task);
	task->DoOnDoneChange(
		[this, task](bool isDone) {
			if (isDone)
			{
				m_tasks.emplace(task);
			}
			else
			{
				m_tasks.erase(task);
			}
		},
		true);
}

Task * GitServer::GetDoneTask() const
{
	return m_doneTasks.empty() ? nullptr : *m_doneTasks.begin();
}
