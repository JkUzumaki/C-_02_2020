#include <iostream>
#include <mutex>
#include <thread>
#include <list>
#include <unistd.h>

std::mutex mtx;
std::list<int> gList;

void addData(int value){
//	std::lock_guard<std::mutex> lg(mtx);
	mtx.lock();
	gList.push_front(value);
	mtx.unlock();
}

void size()
{
	//std::lock_guard<std::mutex> lg(mtx);
	mtx.lock();
	int size = gList.size();
	std::cout << "Size: " << size << std::endl;
	mtx.unlock();
}

int main()
{
	std::thread t1(addData, 100);
	std::thread t2(addData, 101);
	std::thread t3(addData, 102);
	sleep(1);
	std::thread t4(size);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}

