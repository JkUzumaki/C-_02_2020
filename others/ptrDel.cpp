#include<iostream>

int main()
{
	{
		int *ptr = new int;
		*ptr = 100;
		std::cout << "*ptr" << *ptr << std::endl;
		delete ptr;
	ptr = NULL;
		int *p1=ptr;
		std::cout << "ptr " << ptr << "\nAfter delete"<< std::endl;
		std::cout << "p1 " << p1 << "\np1 add"<< std::endl;
		ptr = new int;
		//std::cout << "ptr " << ptr << "\nAfter delete"<< std::endl;
		*ptr = 1000;
		std::cout << "*ptr" <<  *ptr << std::endl;
		delete ptr;
	}
//	*ptr = new int;
}
