#include <iostream>
#include <fstream>
#include <string>

class ston{
private:
	ston(){}
	ston(const ston& r){}
	ston(ston&& r){}
	ston operator=(ston r){}
public:
	static ston* getInstance(){
		if(ptr == NULL)
			ptr = new ston;
		return ptr;
	}
	void WriteFile(std::string str){
		std::fstream f;
		f.open("File.txt", std::fstream::in| std::fstream::out| std::fstream::app);
		f << str;
		f.close();
	}
	static ston* ptr;
};
ston* ston::ptr = NULL;

int main(){
	ston* fptr = ston::getInstance();
	ston* fptr1 = fptr;
	int flag = 1;
	while(flag == 1){
		std::cout << "Do you want to write in file press 1\n";
		std::cin >> flag;
		if(flag == 1){
			std::string str;
			std::cout << "Enter the text to input the file\n";
			std::getline(std::cin, str);
			fptr->WriteFile(str);
		}else{
			flag = 0;
		}
	}
	return 0;
}
