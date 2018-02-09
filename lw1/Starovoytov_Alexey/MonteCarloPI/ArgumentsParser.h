#pragma once
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Argument
{
	string key;
	string value;
};

class ArgumentsParser
{
public:
	ArgumentsParser(int argumentCount, char* argumentStrings[]);
	bool DoesFlagExist(string const& flag) const;
	bool GetStringArgument(string const& key, string& stringArgument) const;
	bool GetIntArgument(string const& key, int& intArgument) const;
	bool GetUIntArgument(string const& key, unsigned int& intArgument) const;

private:
	unordered_map<string, string> m_argumentKeyToValue;
	unordered_set<string> m_flags;

	bool ParseArgument(char* argumentString, Argument& argument);
	bool DoesArgumentExist(string const& key) const;
};
