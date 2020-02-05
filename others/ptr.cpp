#include<iostream>

int main()
{
	int* p = new int;
	int* p1  = p;
	std::cout << "p1 " << p1 << std::endl;
	std::cout << "&p " << &p << std::endl;
}
