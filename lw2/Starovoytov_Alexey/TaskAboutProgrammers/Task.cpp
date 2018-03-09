#include "Task.h"

Task::Task(Programmer * assignee)
	: m_assignee(assignee)
{}

Programmer * Task::GetAssignee()
{
	return m_assignee;
}

bool Task::IsDone() const
{
	return *m_isDone;
}

void Task::SetDone(bool isDone)
{
	if (*m_isDone != isDone)
	{
		*m_isDone = isDone;
		m_doneChangeSignal(isDone);
	}
}

bool Task::IsApproved() const
{
	return *m_isApproved;
}

void Task::SetApproved(bool isApproved)
{
	if (*m_isApproved != isApproved)
	{
		*m_isApproved = isApproved;
		m_approvedChangeSignal(isApproved);
	}
}

boost::signals2::connection Task::DoOnDoneChange(
	const boost::signals2::signal<void(bool isDone)>::slot_type & slot, bool doAction)
{
	if (doAction)
	{
		slot(*m_isDone);
	}
	return m_doneChangeSignal.connect(slot);
}

boost::signals2::connection Task::DoOnApprovedChange(
	boost::signals2::signal<void(bool isDone)>::slot_type const & slot, bool doAction)
{
	if (doAction)
	{
		slot(*m_isApproved);
	}
	return m_approvedChangeSignal.connect(slot);
}
