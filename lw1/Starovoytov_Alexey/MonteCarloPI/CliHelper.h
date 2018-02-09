#pragma once
#include "CliArgument.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class CliHelper
{
public:
	CliHelper(vector<CliArgument> const& cliArguments);
	void ShowHelp() const;
	void ShowHelpForArgument(string const& argumentName) const;

private:
	unordered_map<string, CliArgument> m_cliArgumentByName;

	bool IsArgumentExists(string const& argument) const;
};
