#include <iostream>
#include <Windows.h>

int main()
{
	HW_PROFILE_INFO hwProfileInfo;

	//Writes CurrentHwProfile to the address of hwProfileInfo and checks if it is not NULL
	if (GetCurrentHwProfile(&hwProfileInfo) != NULL)
	{
		//Prints out the output wasn't NULL it will print out the HWID
		std::cout << "HWID: " << hwProfileInfo.szHwProfileGuid << std::endl;
	}
	else
	{
		//If the output was NULL it will give an error message
		std::cout << "Something wen't wrong." << std::endl;
	}
	system("pause");
	return 0;
}