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

int main(){
	Test t;
	Test t1 = t;	
	return 0;
}	
