#include<iostream>

class Test{
public:
	Test()
	{}
	~Test(){}
	Test(const Test &ref){
		std::cout << "CpyConstructor\n";
	}
};

void fun(Test t){
	return ;
}

int main(){
	Test t;
	fun(t);
	return 0;	
}

//Scenarios
// 1. Test t = t1;
// 2. return by value
// 3. send as parameter
