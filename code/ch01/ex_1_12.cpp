#include <iostream>

int main()
{
	int sum = 0;
	
	for (int val = -100; val <= 100; ++val)
	{
		sum += val;
	}
	std::cout << "sum of -100 to 100 inclusive is "
			  << sum << std::endl;
	return 0;
}