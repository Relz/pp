#pragma once
#include <string>

using namespace std;

class CliArgument
{
	friend class CliArgumentBuilder;

public:
	string GetName() const;
	string GetDescription() const;
	string GetDefaultValue() const;
	string GetMinValue() const;
	string GetMaxValue() const;
	bool IsRequired() const;
	bool IsFlag() const;

	friend ostream& operator<<(ostream& os, CliArgument const& cliArgument);

private:
	string m_name;
	string m_description;
	string m_defaultValue;
	string m_minValue;
	string m_maxValue;
	bool m_isRequired = true;
	bool m_isFlag = true;

	CliArgument() = default;
};

class CliArgumentBuilder
{
public:
	CliArgumentBuilder();
	CliArgumentBuilder& SetName(string const& name);
	CliArgumentBuilder& SetDescription(string const& description);
	CliArgumentBuilder& SetDefaultValue(string const& defaultValue);
	CliArgumentBuilder& SetMinValue(string const& minValue);
	CliArgumentBuilder& SetMaxValue(string const& maxValue);
	CliArgumentBuilder& SetIsRequired(bool isRequired);
	CliArgumentBuilder& SetIsFlag(bool isFlag);

	CliArgument Build() const;

private:
	CliArgument m_cliArgument;
};
