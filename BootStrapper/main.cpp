#include <stdio.h>
#include <string>
#include <iostream>

#include "ExecutableInformation.h"
#include "LaunchExectuable.h"

bool stringToBool(std::string myString)
{
	if (myString == "0")
		return false;

	return true;
}

int main(int argc, char *argv[])
{
	std::cout << "Number of arguments: " << argc << std::endl;

	int x = 0;
	execboot::ExecInfo info;

	for (int i = 0; i < argc; i++)
	{
		std::string argCheck = argv[i];
		std::cout << "Argument " << i << ": " << argCheck << std::endl;

		if ( argCheck.find("BootStrapper.exe") != std::string::npos || argCheck == "BootStrapper.exe")
		{
			std::cout << "Found self, skipping" << std::endl;
			continue;
		}

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

	if (x == 1)
	{
		execboot::LaunchExecutable(info.executablePath);
	}
}
