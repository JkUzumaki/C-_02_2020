#include<iostream>

int main()
{
	int *p = new int;
	*p = 101;	
std::cout << "p: " << p  << " " << *p << std::endl;

	delete p;
std::cout << "p: " << p  << " " << *p << std::endl;

	p = nullptr;
	//std::cout << "*p: " << *p << std::endl;
	//int *p1  = p;
	std::cout << "p: " << p << std::endl;
	//std::cout << "*p1: " << *p1 << std::endl;
	//std::cout << "p1: " << p1 << std::endl;
	/*if(p1 == NULL)
		std::cout << "inside if\n";
	else	
		std::cout << "inside else\n";*/
	return 0;
}
