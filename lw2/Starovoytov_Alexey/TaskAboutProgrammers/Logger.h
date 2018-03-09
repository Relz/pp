#pragma once

#include <iostream>
#include <string>
#include <windows.h>

class Logger
{
public:
	static Logger * GetInstance();
	void Print(std::string const & string);

private:
	static Logger * m_instance;
	CRITICAL_SECTION m_criticalSection;

	explicit Logger();
};
