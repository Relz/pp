/*
Задача о программистах.

В отделе работают M программистов.
Каждый программист работает над задачей и отдает её на ревью другому программисту.
Программист проверяет чужую задачу, когда код его собственной уже написан.
По завершении ревью, проверяющий дает ответ: ревью пройдено или ревью не пройдено.
Программист спит, если не пишет код и не проверяет чужой.
Программист просыпается, когда получает заключение от другого программиста.
Если задача отревьювена, программист берется за другую,
иначе он исправляет код и отправляет его на проверку тому же программисту, который его проверял.
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
