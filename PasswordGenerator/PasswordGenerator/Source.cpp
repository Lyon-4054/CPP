#include <iostream>
#include <string>
#include <chrono>


//Program made in C++ by Lyon#4054
//Actually my first time i've put comments in my code lol


char RandomChar()
{
	char data[64] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '0','1','2',
		'3','4','5','6','7','8','9', '#', '!' };
	//Returns random char from data[]
	return data[std::rand()%sizeof(data)];
}

int main(int _inplength, char* _inp[])
{
	//Sets the seed of std::rand(); to the current milliseconds passed since 1970
	std::srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());

	//Checks if there are 2 or 3 params
	if (_inplength == 2 || _inplength == 3)
	{
		//Checks if the first param is for help
		if (std::string(_inp[1])  == "/?" || std::string(_inp[1]) == "-?") 
		{ 
			std::cout << "passgen (password length) (amount of password to generate)" << std::endl; return -1; 
		}
		//Checks if there are 2 params
		if (_inplength == 2)
		{
			//Converts the second param to int and checks if it is more than 0
			if ((int)atof(_inp[1])  > 0)
			{
				//Uses a for loop and prints the return value of RandomChar(); without a new line
				for (int i = 0; i < (int)atof(_inp[1]); i++)
				{
					std::cout << RandomChar();
				}
			}
			//Here it makes the new line
			std::cout << std::endl;
		}
		//Checks if there are 3 params
		else if(_inplength == 3)
		{
			//Converst the second and third param to int and check if they are more than 0
			if ((int)atof(_inp[1])  > 0 && (int)atof(_inp[2]) > 0)
			{
				for (int i = 0; i < (int)atof(_inp[2]); i++)
				{
					//Does the same thing as with 2 params but in a for loop for the amount specified in the third param
					for (int i = 0; i < (int)atof(_inp[1]); i++)
					{
						std::cout << RandomChar();
					}
					std::cout << std::endl;
				}
			}
		}
		//Returns "Invalid input." if the params are wrong
		else { std::cout << "Invalid input." << std::endl; return -1; }
	}
	//Returns "Invalid input." if there are is less than 2 params
	else { std::cout << "Invalid input." << std::endl; return -1; }
	return 0;
}