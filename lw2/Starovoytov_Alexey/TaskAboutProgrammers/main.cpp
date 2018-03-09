/*
������ � �������������.

� ������ �������� M �������������.
������ ����������� �������� ��� ������� � ������ � �� ����� ������� ������������.
����������� ��������� ����� ������, ����� ��� ��� ����������� ��� �������.
�� ���������� �����, ����������� ���� �����: ����� �������� ��� ����� �� ��������.
����������� ����, ���� �� ����� ��� � �� ��������� �����.
����������� �����������, ����� �������� ���������� �� ������� ������������.
���� ������ �����������, ����������� ������� �� ������,
����� �� ���������� ��� � ���������� ��� �� �������� ���� �� ������������, ������� ��� ��������.
*/

#include "GitServer.h"
#include "Programmer.h"
#include "ThreadCollection.h"
#include <iostream>

int main()
{
	unsigned int programmerCount = 5;

	std::vector<Programmer *> programmers;
	GitServer * gitServer = new GitServer();
	ThreadCollection * threadCollection = new ThreadCollection();
	for (unsigned int i = 0; i < programmerCount; ++i)
	{
		Programmer * programmer = new Programmer(i, threadCollection, gitServer);
		programmers.emplace_back(programmer);
		gitServer->ObserveTask(programmer->GetTask());
	}
	threadCollection->Wait();

	return 0;
}
