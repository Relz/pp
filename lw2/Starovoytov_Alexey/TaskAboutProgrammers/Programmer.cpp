#include "Programmer.h"

Programmer::Programmer(unsigned int id, ThreadCollection * threadCollection, GitServer * gitServer)
	: m_id(id)
	, m_task(new Task(this))
{
	ProgrammerActivityData * programmerActivityData = new ProgrammerActivityData();
	programmerActivityData->task = m_task;
	programmerActivityData->gitServer = gitServer;
	threadCollection->Add(Programmer::Activity, programmerActivityData);
}

unsigned int Programmer::GetId() const
{
	return m_id;
}

bool Programmer::IsSleeping() const
{
	return m_task->IsDone();
}

Task * Programmer::GetTask() const
{
	return m_task;
}

DWORD Programmer::Activity(LPVOID CONST data)
{
	ProgrammerActivityData * programmerActivityData = (ProgrammerActivityData *)data;
	Task * task = programmerActivityData->task;
	GitServer * gitServer = programmerActivityData->gitServer;

	std::string const programmerIdString = std::to_string(task->GetAssignee()->GetId());
	while (true)
	{
		if (!task->IsDone())
		{
			std::string message = programmerIdString + " ";
			if (HasProgrammerCompletedTask())
			{
				task->SetDone(true);
				message += "has completed task";
			}
			else
			{
				message += "is still doing his task";
			}
			message += "\n";
			Logger::GetInstance()->Print(message);
		}
		if (task->IsDone())
		{
			Task * anotherDoneTask = gitServer->GetWaitingForReviewTaskExcept(task);
			if (anotherDoneTask == nullptr)
			{
				Logger::GetInstance()->Print(programmerIdString + " is sleeping\n");
			}
			else if (HasProgrammerApprovedPullRequest())
			{
				std::string const pullRequestAssigneeId = std::to_string(anotherDoneTask->GetAssignee()->GetId());
				Logger::GetInstance()->Print(
					programmerIdString + " has approved " + pullRequestAssigneeId + "'s pull request\n");
				anotherDoneTask->SetApproved(true);
			}
			else
			{
				std::string const pullRequestAssigneeId = std::to_string(anotherDoneTask->GetAssignee()->GetId());
				Logger::GetInstance()->Print(
					programmerIdString + " requests changes for " + pullRequestAssigneeId + "'s pull request\n");
				anotherDoneTask->SetDone(false);
			}
		}
		Sleep(1000);
	}
}

bool Programmer::HasProgrammerCompletedTask()
{
	return RandomHelper::GetInstance()->GetRandomInteger(0, 5, GetCurrentThreadId()) == 0;
}

bool Programmer::HasProgrammerApprovedPullRequest()
{
	return RandomHelper::GetInstance()->GetRandomInteger(0, 3, GetCurrentThreadId()) == 0;
}
