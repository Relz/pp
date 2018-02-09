#include "CliHelper.h"

CliHelper::CliHelper(vector<CliArgument> const& cliArguments)
{
	for (CliArgument const& cliArgument : cliArguments)
	{
		m_cliArgumentByName.emplace(cliArgument.GetName(), cliArgument);
	}
}

void CliHelper::ShowHelp() const
{
	cout << "usage: MonteCarloPI.exe ";
	for (pair<string, CliArgument> const& nameToCliArgument : m_cliArgumentByName)
	{
		CliArgument const& cliArgument = nameToCliArgument.second;
		if (!cliArgument.IsRequired())
		{
			cout << "[";
		}
		cout << "--" << nameToCliArgument.first;
		if (!cliArgument.IsFlag())
		{
			cout << "=<" << nameToCliArgument.first << ">";
		}
		if (!cliArgument.IsRequired())
		{
			cout << "]";
		}
		cout << " ";
	}
	cout << "\n";
	for (pair<string, CliArgument> const& nameToCliArgument : m_cliArgumentByName)
	{
		ShowHelpForArgument(nameToCliArgument.first);
	}
}

void CliHelper::ShowHelpForArgument(string const& argumentName) const
{
	if (!IsArgumentExists(argumentName))
	{
		return;
	}
	CliArgument cliArgument = m_cliArgumentByName.at(argumentName);
	cout << cliArgument << "\n";
}

bool CliHelper::IsArgumentExists(string const& argument) const
{
	return m_cliArgumentByName.find(argument) != m_cliArgumentByName.end();
}
