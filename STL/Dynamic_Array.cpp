#include <bits/stdc++.h> 
using namespace std; 

class Dynamic_array { 

	int* arr; 
	int capacity; 
	int current; 

public: 
	Dynamic_array() 
	{ 
		arr = new int[1]; 
		capacity = 1; 
		current = 0; 
	} 

	void push_back(int data) 
	{ 

		if (current == capacity) { 
			int* temp = new int[2 * capacity]; 

			for (int i = 0; i < capacity; i++) { 
				temp[i] = arr[i]; 
			} 

			delete[] arr; 
			capacity *= 2; 
			arr = temp; 
		} 

		arr[current] = data; 
		current++; 
	} 
	
	int size() 
	{ 
		return current; 
	} 

	int getcapacity() 
	{ 
		return capacity; 
	} 
	
	void  erase(int index){
		if(index > size()){
			cout << "index cannot be greater than size \n";
		}else{
			arr[index] = 0;
		}
	}
	
	void clear(){
		for(int i = 0; i < size(); i++){
			arr[i] = 0;
		}
	}
	
	void print() 
	{ 
		for (int i = 0; i < current; i++) { 
			cout << arr[i] << " "; 
		} 
		cout << endl; 
	} 
}; 

int main() 
{ 
	Dynamic_array v; 
	v.push_back(10); 
	v.push_back(20); 
	v.push_back(30); 
	v.push_back(40); 
	v.push_back(50); 
	v.erase(2);
	v.print();
	v.clear();
	v.print();
	std::cout << v.size() << std::endl;
	return 0; 
} 

