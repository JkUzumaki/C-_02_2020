#include<iostream>
/*
	When the recursion is called inside function more than once
	Then such function are known as tree recursion
*/
void fun(int n){
	if(n > 0){
		std::cout << n << std::endl;
		fun(n-1);//Tree recursion
		fun(n-1);//Tree recursion
	}
	return;
}

int main()
{
	fun(4);
	return 0;
}
