//转义s输出 2M new line
#include <iostream>

using namespace std;

int main()
{

	cout << "2M\n" << endl;
	cout << "\062\115\012" << endl;
	cout << "\062\t\115\012" << endl;	
	return 0;
}