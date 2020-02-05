#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

std::mutex mtx;

class stack
{
	int top = -1;
	int *arr;
	int size;
public:
	stack() = delete;
	stack(int data):size(data)
	{ 
		arr = new int [size];
	}
	~stack(){
		delete [] arr;
	}
	//Push
	void push(int value);
	//Pop
	int pop();
	//Display
	void display();
	//Empty
	bool empty();
	//Full
	bool full();
};

bool stack::full(){
	if(top == (size-1))
		return true;
	return false;
}

bool stack::empty(){
	if(top == -1)
		return true;
	return false;
}

void stack::push(int value){
	mtx.lock();
	if(!full()){
		top++;
		arr[top] = value;
	}else{
		std::cout << "Stack is FULL!\n";
	}
	mtx.unlock();
}

int stack::pop(){
	mtx.lock();
	int value = 0;
	if(!empty()){
		value = arr[top];
		arr[top] = 0;
		top--;	
		return value;
	}else{
		std::cout << "Stack is EMPTY!\n";
		return -1;
	}
	mtx.unlock();
}

void stack::display()
{	
	mtx.lock();
	std::cout << "Elements in the stack:\n";
	if(!empty()){
		for(int i = 0; i < top; i++)
			std::cout << arr[i] << " ";
		std::cout << "\n";
	}else{
		std::cout << "Stack is empty!, Nothing to display\n";
	}
	mtx.unlock();
}

void fun()
{	
	int size;
	std::cout << "Enter the size of stack\n";
	std::cin >> size; 	
	stack obj(size);
	int choice = 0;
	int flag = 1;
	while( flag == 1){
		std::thread::id threadId = std::this_thread::get_id();
		std::cout << "Thread Id: " << threadId << "\n";
		std::cout << "Enter the choice:\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
		std::cin >> choice;
		switch(choice){
			case 1:
				{
					int value;
					std::cout << "Enter the value to push:\n";
					std::cin >> value;
					obj.push(value);
				}break;
			case 2:{
					int value = obj.pop();
					if(value == -1)
						std::cout << "Poped value " << value << std::endl;
				}break;
			case 3:
				obj.display();
				break;
			case 4:
				flag = 0;
				break;
			default:
				std::cout << "Invalid entry ...\n";
		}
		sleep(1);
	}

	return ;
}

int main()
{
	std::thread t1(fun);
	std::thread t2(fun);
//	sleep(10);
	t1.join();
	t2.join();
	return 0;
}
