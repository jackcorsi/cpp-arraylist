#include<iostream>
using namespace std;

#include "Array_generic.cpp"
//#include "Array_generic_solved.cpp"

int main()
{  
	cout<< "========== Float Array ==========\n";
   	Array<int> v1;
   	v1.push_back(100);
   	v1.push_back(101);
   	v1.push_back(102);
   	v1.push_back(103);
   	v1.insert(2, 5);	// After this, v1[2] will return 5
   	v1.insert(3, 6);

	Array<int> v2;
	v2 = v1;

   	Array<int>::iterator it = v2.begin();
	for(it=v2.begin(); it<v2.begin()+v2.size(); it++) 
   		cout <<"\n"<< *it << "\n";

	cout << "3rd element = " << v2[2] << "\n";

	cout<< "========== Float Array ==========\n";
   	Array<float> v3;
   	v3.push_back(100.4);
   	v3.push_back(101.3);
   	v3.push_back(102.2);
   	v3.push_back(103.1);
   	v3.insert(2, 5.3);	
   	v3.insert(3, 6.2);

	Array<float> v4;
	v4 = v3;
 
   	Array<float>::iterator itF = v4.begin();
	for(itF=v4.begin(); itF<v4.begin()+v4.size(); itF++) 
   		cout <<"\n"<< *itF << "\n";

	cout << "3rd element = " << v4[2] << "\n";

	v4.pop_back();
	cout<< "After pop_back()\n";
	for(itF=v4.begin(); itF<v4.begin()+v4.size(); itF++) 
   		cout <<"\n"<< *itF << "\n";

	// Try more operations for correctness testing
}
