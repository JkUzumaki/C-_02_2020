#include<iostream>
#include<future>
#include<unistd.h>

int fetcher(){
	sleep(3);
	return 100;	
}

void fn(){
	std::cout << "Inside the fn\n";
}

int main()
{
	std::future<int> fetch = std::async(fetcher);
	fn();
	std::cout << "The received value: " << fetch.get() << std::endl;
	return 0;
}
