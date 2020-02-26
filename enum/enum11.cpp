#include<iostream>

int main()
{
	enum A1{A=1, B, C};
	std::cout << "The enum value A is " << A1::A << std::endl;
	return 0;
}
