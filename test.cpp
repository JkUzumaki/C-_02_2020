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
	Base *b=new Derived();
	Derived *dptr = dynamic_cast<Derived*> (b);
	//bptr.Base::foo();
	dptr->foo();
	return 0;
}
