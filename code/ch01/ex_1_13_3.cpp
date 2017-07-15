#include <iostream>

int main()
{
	int i = 0, j = 0;
	
	std::cout << "input num of i to j is :" << std::endl;

	std::cin >> i >> j;
	if(i<j)
	{
		for( ; i <= j; i++)
		{
			std::cout << i << " ";
		}
	}
	else
	{
		for( ; i >= j; i--)
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;	

	return 0;
}