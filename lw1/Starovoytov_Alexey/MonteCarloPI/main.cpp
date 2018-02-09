#include "ArgumentsParser.h"
#include "CliHelper.h"
#include "PiCalculator.h"
#include <limits>
#include <string>

using namespace std;

const unsigned int ARGUMENT_COUNT_MIN = 0;
const unsigned int ITERATION_COUNT_DEFAULT = 10000;
const unsigned int THREAD_COUNT_DEFAULT = 1;
const string HELP_FLAG_NAME = "help";
const string ITEATION_COUNT_ARGUMENT_NAME = "iteration_count";
const string THREAD_COUNT_ARGUMENT_NAME = "thread_count";

int main(int argc, char* argv[])
{
	CliHelper cliHelper({
		CliArgumentBuilder()
			.SetName(HELP_FLAG_NAME)
			.SetDescription("Shows help")
			.SetIsRequired(false)
			.Build(),
		CliArgumentBuilder()
			.SetName(ITEATION_COUNT_ARGUMENT_NAME)
			.SetDescription("Sets iteration count")
			.SetDefaultValue(to_string(ITERATION_COUNT_DEFAULT))
			.SetMinValue(to_string(numeric_limits<unsigned int>::min()))
			.SetMaxValue(to_string(numeric_limits<unsigned int>::max()))
			.SetIsRequired(false)
			.SetIsFlag(false)
			.Build(),
		CliArgumentBuilder()
			.SetName(THREAD_COUNT_ARGUMENT_NAME)
			.SetDescription("Sets thread count")
			.SetDefaultValue(to_string(THREAD_COUNT_DEFAULT))
			.SetMinValue(to_string(numeric_limits<unsigned int>::min()))
			.SetMaxValue(to_string(numeric_limits<unsigned int>::max()))
			.SetIsRequired(false)
			.SetIsFlag(false)
			.Build(),
	});
	if (argc - 1 < ARGUMENT_COUNT_MIN)
	{
		cliHelper.ShowHelp();
		return EXIT_FAILURE;
	}
	ArgumentsParser argumentsParser(argc, argv);
	if (argumentsParser.DoesFlagExist(HELP_FLAG_NAME))
	{
		cliHelper.ShowHelp();
		return EXIT_SUCCESS;
	}
	unsigned int iterationCount = ITERATION_COUNT_DEFAULT;
	argumentsParser.GetUIntArgument(ITEATION_COUNT_ARGUMENT_NAME, iterationCount);
	unsigned int threadCount = THREAD_COUNT_DEFAULT;
	argumentsParser.GetUIntArgument(THREAD_COUNT_ARGUMENT_NAME, threadCount);
	cout << iterationCount << " " << threadCount << "\n";

	PiCalculator piCalculator(iterationCount, threadCount);

	piCalculator.Calculate();

	cout << "PI: " << piCalculator.GetPiValue() << "\n";
	return EXIT_SUCCESS;
}
