#include <stdio.h>
#include <string>
#include <iostream>

#include <ExecutableInformation.h>
#include <LaunchExecutable.h>

bool stringToBool(std::string myString)
{
	if (myString == "0")
		return false;

	return true;
}

int main(int argc, char *argv[])
{

	int x = 0;
	execboot::ExecInfo info;

	for (int i = 1; i < argc; i++)
	{
		if (x == 0)
		{
			info.executablePath = argv[i];
			std::cout << "About to run: " << info.executablePath << std::endl;
			x++;
			continue;
		}

		if (x == 1)
		{
			std::string myBool = argv[i];

			info.runAsAdmin = stringToBool(myBool);
			x--;
			execboot::LaunchExecutable(info.executablePath, info.runAsAdmin);
		}
		
	}

	// If we ended on a odd number of arguments.
	if (x == 1)
	{
		execboot::LaunchExecutable(info.executablePath);
	}
}
