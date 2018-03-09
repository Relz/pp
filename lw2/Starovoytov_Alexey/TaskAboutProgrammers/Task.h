#pragma once

#include <boost/signals2.hpp>

class Programmer;

class Task
{
public:
	Task(Programmer * m_assignee);
	bool IsDone() const;
	void SetDone(bool isDone);
	boost::signals2::connection DoOnDoneChange(
		boost::signals2::signal<void(bool isDone)>::slot_type const & slot, bool doAction);

private:
	bool m_isDone = false;
	Programmer * m_assignee;
	boost::signals2::signal<void(bool isDone)> m_doneChangeSignal;
};
