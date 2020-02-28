#include<iostream>
/*
	when a recursion happens at the start of the function then
	such function are known as Head recursion
*/

void fun(int n){
	if(n > 0){
		fun(n-1);
		std::cout << "The value of data is " << n << std::endl;
	}
	return;
}
int main()
{
	fun(4);
	std::cout << "This is Head recursion\n";
	return 0;
}
