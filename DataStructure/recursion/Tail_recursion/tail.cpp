#include<iostream>
/*
	When the recursion is the last step inside a function
	Then such function are known as tail recursion
*/
void fun(int n){
	if(n > 0){
		std::cout << n << std::endl;
		fun(n-1);//Tail recursion
	}
	return;
}

int main()
{
	fun(3);
	return 0;
}
