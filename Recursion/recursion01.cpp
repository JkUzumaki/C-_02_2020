#include<iostream>

void fun(int n){
	if(n > 0){
		fun(n-1);
		std::cout << "The value of n " << n << std::endl;
	}
}

int main(){
	fun(3);
}
