#pragma once

#include <string>

namespace execboot
{
	struct ExecInfo
	{
		std::string executablePath;
		bool runAsAdmin;
	};
}
