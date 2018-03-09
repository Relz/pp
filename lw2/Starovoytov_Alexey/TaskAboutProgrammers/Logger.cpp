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
	EnterCriticalSection(&m_criticalSection);
	std::cout << string;
	LeaveCriticalSection(&m_criticalSection);
}

Logger * Logger::m_instance = nullptr;

Logger::Logger()
{
	InitializeCriticalSection(&m_criticalSection);
}
