#include<iostream>

int main()
{
	int* p = new int;
	std::cout << "&p " << &p << std::endl;
	int a = 100;
//	p = &a;
	std::cout << p << a << std::endl;
	delete p;
	std::cout << p << a << std::endl;
//	p = NULL;
	p = &a;
	std::cout << "*p " << *p << std::endl;
	std::cout << "p " << p << std::endl;
	std::cout << "&p " << &p << std::endl;
	std::cout << "a " << &a << std::endl;
}
