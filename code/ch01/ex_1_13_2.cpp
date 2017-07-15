#include <iostream>

int main()
{
	int val = 10;
	
	std::cout << "num of 10 to 0 is ";

	for(; val >= 0; val--)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
	return 0;
}
