#include<iostream>
#include<stdlib.h>
int main()
{
	int i= 49;
	char a[10] = {i};
//	std::cin >> a;
	std::cout <<"a[0] " << a[0] << std::endl;
	i = atoi(a);
	std::cout << "The value entered by user " << i << std::endl;


}
