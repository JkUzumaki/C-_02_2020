#include <iostream>

class Test{
public:
	Test(){}
	~Test(){}
	Test(const Test &ref){
		std::cout << "Copy costructor\n";	
	}
	Test(Test &&ref){
		std::cout << "Move costructor\n";
	}

};

Test fun(){
	Test obj;
	return obj;
}

void fn(Test t){
	return;
}

int main()
{
	Test t;
	//fun();//fn(test());
	fn(t);
	Test t1 = std::move(t);
	return 0;
}
