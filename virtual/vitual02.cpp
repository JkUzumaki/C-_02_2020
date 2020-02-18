#include<iostream>

class Base{
//public:
	virtual void fun(){}//= 0;
};

class Derived: public Base{
public:
	void fun(){
		std::cout << "Derived\n";
	}
};

int main(){
	Base* bptr = new Derived;
	bptr->fun();
}
