#pragma once

#include <boost/signals2.hpp>

class Programmer;

class Task
{
public:
	Task(Programmer * m_assignee);
	Programmer * GetAssignee();
	bool IsDone() const;
	void SetDone(bool isDone);
	bool IsApproved() const;
	void SetApproved(bool isApproved);
	boost::signals2::connection DoOnDoneChange(
		boost::signals2::signal<void(bool isDone)>::slot_type const & slot, bool doAction = false);
	boost::signals2::connection DoOnApprovedChange(
		boost::signals2::signal<void(bool isDone)>::slot_type const & slot, bool doAction = false);

private:
	bool * m_isDone = new bool(false);
	bool * m_isApproved = new bool(false);
	Programmer * m_assignee;
	boost::signals2::signal<void(bool isDone)> m_doneChangeSignal;
	boost::signals2::signal<void(bool isApproved)> m_approvedChangeSignal;
};
