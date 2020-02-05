#include<iostream>
#include<thread>
#include<unistd.h>

//Odd function
void odd(int num){
	std::cout << "odd: " << num << std::endl;
}
//Even function
void even(int num){
	std::cout << "even: " << num << std::endl;
}

//Main function
int main()
{
	for(int i = 1; ;++i){
		std::thread thrd_odd(odd, i);
		sleep(1);
		std::thread thrd_even(even, ++i);
		sleep(1);
		thrd_odd.join();
		thrd_even.join();
	}
	return 0;
}
