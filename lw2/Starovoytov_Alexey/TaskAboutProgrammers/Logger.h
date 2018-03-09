#pragma once

#include "CriticalSectionHelper.h"
#include <iostream>
#include <string>

class Logger
{
public:
	static Logger * GetInstance();
	void Print(std::string const & string);

private:
	static Logger * m_instance;

	explicit Logger() = default;
};
