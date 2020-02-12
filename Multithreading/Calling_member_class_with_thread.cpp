#include<iostream>
#include<thread>
#include<unistd.h>

class test{
public: 
    std::thread t;
    test(){
        t = std::thread(&test::fun, this);
    }
    ~test(){
        if(t.joinable()){
            sleep(1);
            std::cout << "thread is joinable\n";
            t.join();
        }
    }
    void fun(){
		std::cout << "test::function\n";
	}
};
int main(){
	test obj;
    return 0;
}
