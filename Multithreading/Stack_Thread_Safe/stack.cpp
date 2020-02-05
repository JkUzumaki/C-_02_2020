#include<iostream>
#include<mutex>
#include<thread>
#include<stack>
#include<unistd.h>

template <typename T>
class thread_safe_stack
{
	std::stack<T> st;
	std::mutex m;	
public:
	void push(T element){
		std::lock_guard<std::mutex> lg(m);
		st.push(element);
	}
	//RAII top
	std::shared_ptr<T> top(){
		std::lock_guard<std::mutex> lg(m);
		if(st.empty()){
			throw std::runtime_error("Run time error\n");
		}
		std::shared_ptr<T> res(st.top());
		st.pop();
		return res;
	}
	//RAII pop
	void pop(){
		std::lock_guard<std::mutex> lg(m);
		if(st.empty())
			throw std::runtime_error("Stack is empty");
		//int value = *(st.top().get());
		st.pop();
	}
	//Empty
	bool empty()
	{
		std::lock_guard<std::mutex> lg(m);
		return st.empty();
	}	
	//Size
	size_t size()
	{
		std::lock_guard<std::mutex> lg(m);
		return st.size();
	}	
};

void fun()
{
	std::mutex m;

	int choice = 0;
	int flag = 1;
	thread_safe_stack<int> obj;

	while(flag == 1){
		std::thread::id threadId = std::this_thread::get_id();
		std::cout << "Current thread " << threadId << std::endl;
		std::cout << "Enter the response:\n1.Push\n2.pop\n3.size\n4.exit\n";
		std::cin >> choice;
		m.lock();
		switch(choice){
			case 1:{
				int value;
				std::thread::id threadId = std::this_thread::get_id();
		                std::cout << "Current thread " << threadId << std::endl;

				std::cout << "Enter the value\n";
				std::cin >> value;
				obj.push(value);
				}break;
			case 2:
				obj.pop();
				break;
			case 3:
				obj.size();
				break;
			case 4:
				flag = 0;
				break;		
			default:
				std::cout << "Invalid entry...\n";
		} 
		m.unlock();
	}
}

int main()
{
	std::thread t1(fun);
	std::thread t2(fun);
//	sleep(60);
	t1.join();
	t2.join();
	return 0;
}
