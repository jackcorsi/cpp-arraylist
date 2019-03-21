#include<iostream>
using namespace std;

#include "Array_int.cpp"

int main()
{  
   	Array v1;
   	v1.push_back(100);
   	v1.push_back(101);
   	v1.push_back(102);
   	v1.push_back(103);
   	v1.insert(2, 5);	
   	v1.insert(3, 6);

   	Array::iterator it = v1.begin();

	cout<<"Printing Array v1\n";
	for(it=v1.begin(); it<v1.begin()+v1.size(); it++) 
   		cout <<"\n"<< *it << "\n";

	
	
	/*
	// This section works when assignment operator is defined.
	Array v2;
	v2 = v1;		

	cout<<"Printing Array v2\n";
	for(it=v2.begin(); it<v2.begin()+v2.size(); it++) 
   		cout <<"\n"<< *it << "\n";
	*/


}

