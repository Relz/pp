#pragma once

#include <windows.h>

class CriticalSectionHelper
{
public:
	static CriticalSectionHelper * GetInstance();
	void Enter();
	void Leave();

private:
	static CriticalSectionHelper * m_instance;
	CRITICAL_SECTION m_criticalSection;

	explicit CriticalSectionHelper();
};
