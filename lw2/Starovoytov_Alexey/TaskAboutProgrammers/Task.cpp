#include "Task.h"

Task::Task(Programmer * m_assignee)
{
	m_assignee = m_assignee;
}

void Task::SetDone(bool isDone)
{
	m_done = isDone;
}
