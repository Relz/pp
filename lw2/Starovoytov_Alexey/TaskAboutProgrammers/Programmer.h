#pragma once

#include "Task.h"

class Programmer
{
public:
	Programmer();
	void Sleep();
	void WakeUp();

private:
	bool m_sleep = true;
	Task * m_task;
};
