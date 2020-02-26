#include <iostream>

int factorial(int number){
	static int num = 1;
	if(number > 0){
		num *= number;
		factorial(number-1);
	}
	return num;
}

int main(){
	int number = 0;
	int factor = 0;
	std::cout << "Enter the number:\n";
	std::cin >> number;

	factor = factorial(number);

	std::cout << "The factorial of the number " << number << " is " << factor << std::endl;
	return 0;	
}
