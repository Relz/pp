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
#include <iostream>

int main()
{
	unsigned int programmerCount = 5;

	std::vector<Programmer *> programmers;
	GitServer gitServer;
	for (unsigned int i = 0; i < programmerCount; ++i)
	{
		Programmer * programmer = new Programmer(i);
		programmers.emplace_back(programmer);
		gitServer.ObserveTask(programmer->GetTask());
	}

	return 0;
}
