#pragma once

class Programmer;

class Task
{
public:
	Task(Programmer * m_assignee);
	void SetDone(bool isDone);

private:
	bool m_done = false;
	Programmer * m_assignee;
};
