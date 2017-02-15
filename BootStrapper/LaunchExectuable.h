#pragma once

#ifdef _WIN32
#include <Windows.h>
#include <shellapi.h>
#include <tchar.h>
#endif

#include <string>
#include <codecvt>
#include <locale>

namespace execboot
{
	void LaunchExecutable(std::string executableName, bool asAdmin = false)
	{
		//std::to_wstring(executableName.c_str());
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		std::wstring string = converter.from_bytes(executableName);
		SHELLEXECUTEINFO shExInfo = { 0 };
		shExInfo.cbSize = sizeof(shExInfo);
		shExInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		shExInfo.hwnd = 0;

		if (asAdmin)
			shExInfo.lpVerb = _T("runas");                // Operation to perform
		else
			shExInfo.lpVerb = _T("open");

		shExInfo.lpFile = string.c_str();       // Application to start    
		shExInfo.lpParameters = _T("");                  // Additional parameters
		shExInfo.lpDirectory = 0;
		shExInfo.nShow = SW_SHOW;
		shExInfo.hInstApp = 0;

		if (ShellExecuteEx(&shExInfo))
		{
			WaitForSingleObject(shExInfo.hProcess, INFINITE);
			CloseHandle(shExInfo.hProcess);
		}
	}

}
