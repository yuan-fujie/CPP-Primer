//test
#include <iostream>

using namespace std;
std::string global_str;
int global_int;

int main()
{
	int local_int;
	std::string local_str;
	
	cout << "global_str ";
	cout << global_str ;
	cout << " global_int " ;
	cout << global_int ;

	cout << " local_int " ;
	cout << local_int ;
	cout << " local_int " ;
	cout << local_int ;

	cout << endl;

	return 0;
}