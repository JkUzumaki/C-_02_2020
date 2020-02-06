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

Test fun(){
	Test t;
	return t;
}

int main(){
	//Test t = fun();
	fun();
	return 0;	
}

//Scenarios
// 1. Test t = t1;
// 2. return by value
// 3. send as parameter
