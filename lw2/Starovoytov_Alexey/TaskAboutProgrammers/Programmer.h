#pragma once

#include "Task.h"

class Programmer
{
public:
	Programmer(unsigned int id);
	Task * GetTask() const;
	void Sleep();
	void WakeUp();

private:
	unsigned int m_id;
	bool m_sleep = true;
	Task * m_task;
};
