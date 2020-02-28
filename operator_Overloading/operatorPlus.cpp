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
	Test(const Test& ref){
		std::cout << "Copy constructor\n";
	}
	Test(Test && ref){
		std::cout << "Move constructor\n";
	}
	Test operator+(Test& ref){
		Test temp;
		temp.data1 = data1 + ref.data1;
		temp.str = str + ref.str;
		return temp;
	}
	void operator&(){
		
		//std::cout << "address of data1: "<< &data1 << std::endl;
		//std::cout << "address of str "<< &str << std::endl;
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
	friend std::ostream& operator<<(std::ostream &out, const Test& ref);
	friend std::istream& operator>>(std::istream &in, Test& ref);
};

std::ostream& operator<<(std::ostream &out, const Test& ref){
	out << "int value " << ref.data1 << " string value " << ref.str << std::endl;
	return out;
}


std::istream& operator>>(std::istream &in, Test& ref){
	std::cout << "Enter the int value\n";
	in >> ref.data1;
	std::cout << "Enter the string\n";
	in >> ref.str;
	return in;
}

int main(){
	Test obj1(1, "Hi");
	Test obj2 = std::move(obj1);
	std::cin >> obj1;
	std::cout << obj1;
}
