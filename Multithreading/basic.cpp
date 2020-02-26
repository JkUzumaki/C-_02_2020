#include<iostream>
#include<thread>
#include<mutex>
std::mutex mtx;
int global = 0;
void add(){
	mtx.lock();
	//int c = a+b;
	//std::cout << "The sum of " << a << "+" << b << " = " << c <<std::endl;
	for(int i = 0;i < 5; i++){
		global += i;
	std::cout << global << std::endl;
	}
	mtx.unlock();
	return;
}

int main(){
	std::thread t(add);
	std::thread t1(add);
	//add();
	t.join();
	t1.join();
	std::cout << "global " << global << std::endl;
	return 0;
}
