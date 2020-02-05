#include<iostream>
#include<mutex>
#include<thread>
#include<stack>

template <typename T>
class thread_safe_stack
{
	std::stack<T> st;
	std::mutex mtx;	
public:
	thread_safe_stack operator()(){
		return this;
	}
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
		if(st.empty)
			throw std::runtime_error("Stack is empty");
		value = *(st.top().get());
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
	
}
int main()
{
	std::thread t1(fun);
	sleep(60);
	t1.join();
	return 0;
}
