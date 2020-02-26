#include<iostream>
#include<unistd.h>

int main(){
	if(fork()){
		std::cout << "P_Child\n";
	}else{
		std::cout << "C_Parent\n";
		//sleep(1);
		//std::cout << 
	}
}
