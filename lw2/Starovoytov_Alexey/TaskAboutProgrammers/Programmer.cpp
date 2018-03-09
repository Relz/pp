#include "Programmer.h"

Programmer::Programmer(unsigned int id)
	: m_id(id)
	, m_task(new Task(this))
{}

Task * Programmer::GetTask() const
{
	return m_task;
}

void Programmer::Sleep()
{
	m_sleep = true;
}

void Programmer::WakeUp()
{
	m_sleep = false;
}
