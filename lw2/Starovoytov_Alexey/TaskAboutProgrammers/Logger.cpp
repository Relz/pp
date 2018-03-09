#include "Logger.h"

Logger * Logger::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new Logger();
	}
	return m_instance;
}

void Logger::Print(std::string const & string)
{
	CriticalSectionHelper::GetInstance()->Enter();
	std::cout << string;
	CriticalSectionHelper::GetInstance()->Leave();
}

Logger * Logger::m_instance = nullptr;
