#include<iostream>

class Base{
public:
	virtual void fun(){
		std::cout << "Base::fun\n";
	}
};
class Derived:public Base{
public:
	void fun(){
		std::cout << "Der::fun\n";
	}	
};
int main(){
	Derived *d = dynamic_cast<Derived*>(new Base);//Derived;
	d->fun();
}
