class  IntArray
{

	private:
    unsigned int array_size;		// Number of elements in Array
    unsigned int array_capacity;	// Capacity of Array 
    int * buffer;					// Buffer where elements are stored


	public:
    typedef int * iterator;			// used to access elements of Array

    IntArray();						// default constructor
    IntArray(unsigned int size);
    ~IntArray();

    unsigned int capacity();		// Returns capacity of Array
    unsigned int size();			// Returns number of elements in Array 
    iterator begin();				// Returns start of Array
    iterator end();					// Returns end of Array
    int & front();					// Front element
    int & back();						// End element	
    void push_back(const int & value); 	// Inserts new element in the end
    void pop_back();  					// Pop end element and decrement array_size

    void reserve(unsigned int capacity);   	// Used to modify capacity of Array
    void resize(unsigned int size);   		// Used to resize array

    int & operator[](unsigned int index);  	// Overloaded [] for array-like access
    IntArray & operator=(const IntArray &);		// Overloaded assignment operator; You need to define this operator
	void insert(unsigned int position, int value);	// Inserts an element with 'value' in the 'begin()+position' index
													// You need to define this function		
    void clear();									// Clears Array
};

IntArray::IntArray()
{
    array_capacity = 0;
    array_size = 0;
    buffer = 0;
}


IntArray::IntArray(unsigned int size)
{
    array_capacity = size;
    array_size = size;
    buffer = new int[size];
}

/* 
 * You need to define assignment operator in Array_generic.cpp.
*/
IntArray & IntArray::operator = (const IntArray & v)
{
    delete[ ] buffer;

	/*
	YOUR CODE HERE
	*/

    return *this;
}


/* 
 * array-like selection operator '[]'
 * E.g. Array A;  A[n-1] returns the n th element from the front. 
*/
int& IntArray::operator[](unsigned int index)
{
	return buffer[index];
}  

IntArray::iterator IntArray::begin()
{
    return buffer;
}

IntArray::iterator IntArray::end()
{
    return buffer + size();
}

int& IntArray::front()
{
    return buffer[0];
}

int& IntArray::back()
{
    return buffer[array_size - 1];
}

void IntArray::push_back(const int & v)
{
    if (array_size >= array_capacity)
        reserve(array_capacity + 10);
    buffer [array_size++] = v;
}

void IntArray::pop_back()
{
    array_size--;
}

void IntArray::reserve(unsigned int capacity)
{
    if(buffer == 0)
    {
        array_size = 0;
        array_capacity = 0;
    }    
    int * Newbuffer = new int [capacity];
    unsigned int new_Size = capacity < array_size ? capacity : array_size;

    for (unsigned int i = 0; i < new_Size; i++)
        Newbuffer[i] = buffer[i];

    array_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}

unsigned int IntArray::size()
{
    return array_size;
}

void IntArray::resize(unsigned int size)
{
    reserve(size);
    array_size = size;
}

unsigned int IntArray::capacity()
{
    return array_capacity;
}

/* You need to define this function in Array_generic.cpp.
 * Inserts an element with 'value' in the 'begin()+position' index.
 * E.g. Existing Array A={1,3,9,12}. 
 * After insert(2,7) it becomes A={1,3,7,9,12}. 	
*/ 
void IntArray::insert(unsigned int position, int value)
{
	/*
	YOUR CODE HERE
	*/

}


void IntArray::clear()
{
    array_capacity = 0;
    array_size = 0;
    buffer = 0;
}


IntArray::~IntArray()
{
	delete[ ] buffer;
}


