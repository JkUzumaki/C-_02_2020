#include<iostream>
//#include<bits/stdc++.h>
class Test{
public:
	int data1;
	std::string str;
	Test(int a, std::string str1){
		data1  = a;
		str = str1;
	}
	Test(){}
	Test operator+(Test& ref){
		Test temp;
		temp.data1 = data1 + ref.data1;
		temp.str = str + ref.str;
		return temp;
	}
	void operator&(){
		
		std::cout << "address of data1: "<< &data1 << std::endl;
		std::cout << "address of str "<< &str << std::endl;
	}
	bool operator<(Test& ref){
		if(data1 < ref.data1){
			return true;
		}
		return false;
	}
	void operator++()//pre
	{
		std::cout << "Pre increment\n";
		data1++;
	}
	void operator++(int)//pre
	{
		std::cout << "Post increment\n";
		data1++;
	}
	friend ostream& operator<<(ostream &out, const Test& ref);
	friend istream& operator>>(istream &in, Test& ref);
};

ostream& operator<<(ostream &out, const Test& ref){
	out << "int value " << ref.data1 << " string value " << ref.str << std::endl;
	return out;
}


istream& operator>>(istream &in, Test& ref){
	std::cout << "Enter the int value\n";
	in >> ref.data1;
	std::cout << "Enter the string\n";
	in >> ref.str;
	return in;
}

int main(){
	Test obj1(10, "Hello");
	Test obj2(5, "World");
	obj1++;
	&obj1;
	std::cout << obj1.data1 << std::endl;
	Test obj3 = obj1 + obj1 + obj2;
	if(obj2 < obj1){
		std::cout << "Obj1 is less\n";
	}else{
		std::cout << "Obj1 is NOT less\n";

	}
	std::cout << obj3.data1 << " " << obj3.str << std::endl;
}
