#include "Task.h"

Task::Task(Programmer * m_assignee)
{
	m_assignee = m_assignee;
}

bool Task::IsDone() const
{
	return m_isDone;
}

void Task::SetDone(bool isDone)
{
	if (m_isDone != isDone)
	{
		m_isDone = isDone;
		m_doneChangeSignal(isDone);
	}
}

boost::signals2::connection Task::DoOnDoneChange(
	const boost::signals2::signal<void(bool isDone)>::slot_type & slot, bool doAction = false)
{
	if (doAction)
	{
		slot(m_isDone);
	}
	return m_doneChangeSignal.connect(slot);
}
