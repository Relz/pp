#include "Programmer.h"

Programmer::Programmer()
{
	m_task = new Task(this);
}

void Programmer::Sleep()
{
	m_sleep = true;
}

void Programmer::WakeUp()
{
	m_sleep = false;
}
