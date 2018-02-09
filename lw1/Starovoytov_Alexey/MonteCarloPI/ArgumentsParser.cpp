#include "ArgumentsParser.h"

ArgumentsParser::ArgumentsParser(int argumentCount, char* arguments[])
{
	for (size_t i = 1; i < argumentCount; ++i)
	{
		Argument argument;
		if (ParseArgument(arguments[i], argument))
		{
			if (argument.value.empty())
			{
				m_flags.emplace(argument.key);
			}
			else
			{
				m_argumentKeyToValue.emplace(argument.key, argument.value);
			}
		}
	}
}

bool ArgumentsParser::DoesFlagExist(string const& flag) const
{
	return m_flags.find(flag) != m_flags.end();
}

bool ArgumentsParser::GetStringArgument(string const& key, string& stringArgument) const
{
	if (!DoesArgumentExist(key))
	{
		return false;
	}
	stringArgument = m_argumentKeyToValue.at(key);
	return true;
}

bool ArgumentsParser::GetIntArgument(string const& key, int& intArgument) const
{
	string stringArgument;
	if (!GetStringArgument(key, stringArgument))
	{
		return false;
	}
	try
	{
		intArgument = stoi(stringArgument);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool ArgumentsParser::GetUIntArgument(string const& key, unsigned int& intArgument) const
{
	string stringArgument;
	if (!GetStringArgument(key, stringArgument))
	{
		return false;
	}
	try
	{
		intArgument = stoul(stringArgument);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool ArgumentsParser::ParseArgument(char* argumentString, Argument& argument)
{
	bool result = false;
	cmatch matches;
	regex_match(argumentString, matches, regex("--([_a-zA-Z0-9]+)(=([_a-zA-Z0-9]+))?"));
	if (matches.size() == 4)
	{
		result = true;
		argument.key = matches.str(1);
		if (!matches.str(3).empty())
		{
			argument.value = matches.str(3);
		}
	}

	return result;
}

bool ArgumentsParser::DoesArgumentExist(string const& key) const
{
	return m_argumentKeyToValue.find(key) != m_argumentKeyToValue.end();
}
