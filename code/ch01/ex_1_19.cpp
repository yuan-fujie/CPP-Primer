#include <iostream>

int main()
{
	int i = 0, j = 0;
	
	std::cout << "input num of i to j is :" << std::endl;

	std::cin >> i >> j;
	if(i<j)
	{
		while(i <= j)
		{
			std::cout << i << " ";
			i++;
		}
	}
	else
	{
		while(i >= j)
		{
			std::cout << i << " ";
			i--;
		}
	}
	std::cout << std::endl;	

	return 0;
}