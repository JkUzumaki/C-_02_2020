#include<iostream>

class Base{
public:
Base(){
std::cout<<"Base"<<std::endl;
}

	virtual void foo(){
		std::cout << "Base Function\n";
	}
};

class Derived:public Base
{
public:
Derived(){
std::cout<<"Derived"<<std::endl;
}

	void foo(){
		std::cout << "Derived function\n";
	}
};

int main()
{
	Derived d;
	Base b1 = d;	
	Base &b = d;
	b1.foo();
	b.foo();
	return 0;
}
