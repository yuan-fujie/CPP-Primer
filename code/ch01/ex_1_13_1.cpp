#include <iostream>

int main()
{
	int sum = 0, val = 50;
	
	for(; val <= 100; ++val)
	{
		sum += val;
	}
	std::cout << "sum of 50 to 100 inclusive is "
			<< sum << std::endl;
			
	return 0;
}