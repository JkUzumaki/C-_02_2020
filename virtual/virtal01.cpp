#include<iostream>

class Base{
public:
	//virtual 
	void fun(){
		std::cout << "Base::fun\n";
	}
	void fun2(){
		std::cout << "Base::fun2\n";
	}
};

class Derived: public Base{
public:
	//virtual 
	void fun(){
		std::cout << "Derived::fun\n";
	}
	void fun3(){
		std::cout << "Derived::fun3\n";
	}
};
int main(){
	Base* bptr = new Base();
	bptr->fun();
	bptr->fun2();
	bptr->fun3();
	return 0;
}
