#include <iostream>
//Prototype
void funB(int n);

//Declaration
void funA(int n){
	if(n > 0){
		std::cout << n << std::endl;
		funB(n-1);
	}
}
//Declaration
void funB(int n){
	if(n > 1){
		std::cout << n << std::endl;
		funA(n/2);
	}
}

int main(){
	funA(20);
	return 0;
}
