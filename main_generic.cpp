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
   	v3.push_back(100.4f);
   	v3.push_back(101.3f);
   	v3.push_back(102.2f);
   	v3.push_back(103.1f);
   	v3.insert(2, 5.3f);
   	v3.insert(3, 6.2f);

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
	Array <int> nums(3);
	cout << "nums.size():" << nums.size() << endl;
	cout << "nums.capacity():" << nums.capacity() << endl;
	cout << "Inserting 4" << endl;
	nums.push_back(4);

	cout << "nums.size():" << nums.size() << endl;
	cout << "nums.capacity():" << nums.capacity() << endl;
	cout << "Inserting 9" << endl;
	nums.push_back(9);

	cout << "nums.size():" << nums.size() << endl;
	cout << "nums.capacity():" << nums.capacity() << endl;
	cout << "Inserting 72" << endl;
	nums.push_back(72);

	cout << "nums.size():" << nums.size() << endl;
	cout << "nums.capacity():" << nums.capacity() << endl;
	cout << "Inserting -10" << endl;
	nums.push_back(-10);

	cout << "nums.size():" << nums.size() << endl;
	cout << "nums.capacity():" << nums.capacity() << endl;
	cout << "Inserting -10" << endl;

	cout << "nums[3]=" << nums[3] << endl;
	cout << "popping back" << endl;
	nums.pop_back();
	cout << "nums[2]=" << nums[2] << endl;

	cout << "reserving 30" << endl;
	nums.reserve(30);

	cout << "nums[2]=" << nums[2] << endl;
	cout << "nums.capacity():" << nums.capacity() << endl;

	cout << "Attempting to insert at position 99" << endl;
	try {
		nums.insert(99, 6);
	} catch (std::out_of_range &e) {
		cout << "Exception was thrown";
	}
}
