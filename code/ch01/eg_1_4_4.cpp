//统计一个值连续出现多少次

#include <iostream>

int main()
{
	//currVal是我们正在统计的数；我们将读入新值存入val
	int currVal = 0, val = 0;
	//读取第一个数，并确保有数据可以处理
	if (std::cin >> currVal)
	{
		int cnt = 1;	//保存我们正在处理当前值的个数
		while (std::cin >> val)		//读取剩余的数
		{
			if (val == currVal)		//如果值相同
			{
				++cnt;				//将cnt加1
			}
			else
			{
				std::cout << currVal << " occurs "
						  << cnt << " times " << std::endl;
				currVal = val;		//记住新值
				cnt = 1;			//重置计数器
			}
		}//while end
		std::cout << currVal << " occurs "
				  << cnt << " times " << std::endl;
				  
	}//if end

	return 0;
}