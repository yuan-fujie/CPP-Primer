#include <iostream>

int main()
{
	int val = 10;
	
	std::cout << "num of 10 to 0 is ";

	while(val >= 0)
	{
		std::cout << val << " 	";
		val--;
	}
	std::cout << std::endl;
	return 0;
}