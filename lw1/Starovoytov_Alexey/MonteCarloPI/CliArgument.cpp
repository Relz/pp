#include "CliArgument.h"

string CliArgument::GetName() const
{
	return m_name;
}

string CliArgument::GetDescription() const
{
	return m_description;
}

string CliArgument::GetDefaultValue() const
{
	return m_defaultValue;
}

string CliArgument::GetMinValue() const
{
	return m_minValue;
}

string CliArgument::GetMaxValue() const
{
	return m_maxValue;
}

bool CliArgument::IsRequired() const
{
	return m_isRequired;
}

bool CliArgument::IsFlag() const
{
	return m_isFlag;
}

ostream& operator<<(ostream& os, CliArgument const& cliArgument)
{
	os << cliArgument.GetName() << ": \n";
	if (!cliArgument.GetDescription().empty())
	{
		os << "\tDescription: " << cliArgument.GetDescription() << "\n";
	}
	if (!cliArgument.GetDefaultValue().empty())
	{
		os << "\tDefault value: " << cliArgument.GetDefaultValue() << "\n";
	}
	if (!cliArgument.GetMinValue().empty())
	{
		os << "\tMin value: " << cliArgument.GetMinValue() << "\n";
	}
	if (!cliArgument.GetMaxValue().empty())
	{
		os << "\tMax value: " << cliArgument.GetMaxValue() << "\n";
	}
	os << "\tRequired: " << (cliArgument.IsRequired() ? "True" : "False") << "\n";
	return os;
}

CliArgumentBuilder::CliArgumentBuilder()
	: m_cliArgument(CliArgument())
{
}

CliArgumentBuilder& CliArgumentBuilder::SetName(string const& name)
{
	m_cliArgument.m_name = name;
	return *this;
}

CliArgumentBuilder& CliArgumentBuilder::SetDescription(string const& description)
{
	m_cliArgument.m_description = description;
	return *this;
}

CliArgumentBuilder& CliArgumentBuilder::SetDefaultValue(string const& defaultValue)
{
	m_cliArgument.m_defaultValue = defaultValue;
	return *this;
}

CliArgumentBuilder& CliArgumentBuilder::SetMinValue(string const& minValue)
{
	m_cliArgument.m_minValue = minValue;
	return *this;
}

CliArgumentBuilder& CliArgumentBuilder::SetMaxValue(string const& maxValue)
{
	m_cliArgument.m_maxValue = maxValue;
	return *this;
}

CliArgumentBuilder& CliArgumentBuilder::SetIsRequired(bool isRequired)
{
	m_cliArgument.m_isRequired = isRequired;
	return *this;
}

CliArgumentBuilder& CliArgumentBuilder::SetIsFlag(bool isFlag)
{
	m_cliArgument.m_isFlag = isFlag;
	return *this;
}

CliArgument CliArgumentBuilder::Build() const
{
	return m_cliArgument;
}
