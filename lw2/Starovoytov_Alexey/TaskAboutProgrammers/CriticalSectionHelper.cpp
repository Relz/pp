#include "CriticalSectionHelper.h"

CriticalSectionHelper * CriticalSectionHelper::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new CriticalSectionHelper();
	}
	return m_instance;
}

CriticalSectionHelper::~CriticalSectionHelper()
{
	DeleteCriticalSection(&m_criticalSection);
	delete m_instance;
	m_instance = nullptr;
}

void CriticalSectionHelper::Enter()
{
	EnterCriticalSection(&m_criticalSection);
}

void CriticalSectionHelper::Leave()
{
	LeaveCriticalSection(&m_criticalSection);
}

CriticalSectionHelper * CriticalSectionHelper::m_instance = nullptr;

CriticalSectionHelper::CriticalSectionHelper()
{
	InitializeCriticalSection(&m_criticalSection);
}
