#include <iostream>
#include <Windows.h>

int main()
{
	HW_PROFILE_INFO hwProfileInfo;

	if (GetCurrentHwProfile(&hwProfileInfo) != NULL)
	{
		std::cout << "HWID: " << hwProfileInfo.szHwProfileGuid << std::endl;
	}
	else
	{
		std::cout << "Something wen't wrong." << std::endl;
	}
	system("pause");
	return 0;
}