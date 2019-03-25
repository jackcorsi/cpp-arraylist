#include <stdexcept>

template<class T>
class Array {
private:
	static const int REALLOC_INCREMENT = 10;

	unsigned int array_size;
	unsigned int array_capacity;
	T *buffer;

public:
	typedef T *iterator;

	//Creates an Array with size and capacity 0 - no internal buffer is allocated
	Array();

	//Creates an Array with this value as the initial capacity of the internal buffer
	Array(unsigned int capacity);

	//Creates an array with internal buffer size equal to that of other, and copies the contents
	//of other to this array using the equals operator on each element
	Array(const Array<T> &other);

	~Array();

	//Gets the current capacity of this Array's internal buffer
	unsigned int capacity() const;

	//Gets the size value of this Array, representing how many elements of the Array are in use
	unsigned int size() const;

	//Returns a pointer to the first element within the Array
	iterator begin() const;

	//Returns a pointer to the last element within the Array (size - 1)
	iterator end() const;

	//Returns the first element within the Array
	//Warning: this operation is unchecked and unsafe for Arrays with no initialised storage buffer
	T &front() const;

	//Returns the last element within the Array
	//Warning: this operation is unchecked and unsafe for Arrays with size = 0
	T &back() const;

	//Inserts a new element, incrementing size and reallocating the buffer to accommodate if necessary
	void push_back(const T &elem);

	//Decrements size to classify the last element of the Array as no longer in use
	void pop_back();

	//Ensures that the buffer has enough available memory to contain this many elements without needing
	//to resize after this call
	void reserve(unsigned int capacity);

	//Reallocates the buffer with a capacity equal to size, so that there is no unused space
	void shrink_to_fit();

	//Arbitrary modification of the Array's size - use with care
	//the buffer will be appropriately reallocated if the given new size value is greater than its size
	void resize(unsigned int size);

	//Unchecked access to the index'th element of the Array
	T &operator[](unsigned int index) const;

	Array<T> &operator=(const Array<T> &);

	//Insert an element within the Array
	//If position < size, all elements at and after this position will be shifted up one position using their operator=
	//If position > size, this method throws an std::out_of_range so as to not leave unused "empty" spaces
	//	within the "size" portion of the buffer
	void insert(unsigned int position, const T &value);

	//Clears all contents of the Array and restores it to a state as though it has just been created
	//using the default constructor
	void clear();
};

template<class T>
Array<T>::Array() {
	array_capacity = 0;
	array_size = 0;
	buffer = nullptr;
}

template<class T>
Array<T>::Array(unsigned int capacity) {
	array_size = 0;
	buffer = new T[array_capacity = capacity];
}

template<class T>
Array<T>::Array(const Array<T> &other) { //Copy constructor
	buffer = new T[array_capacity = other.size()];

	for (unsigned int i = 0; i < (array_size = other.size()); i++)
		buffer[i] = other[i];
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (array_capacity < other.size()) { //Reserve enough space for other's elements
		delete[] buffer;
		buffer = new T[array_capacity = other.size()];
	}

	for (unsigned int i = 0; i < (array_size = other.size()); i++)
		buffer[i] = other[i];

	return *this;
}

template<class T>
T &Array<T>::operator[](unsigned int index) const {
	return buffer[index];
}

template<class T>
T *Array<T>::begin() const {
	return buffer;
}

template<class T>
T *Array<T>::end() const {
	return buffer + array_size - 1;
}

template<class T>
T &Array<T>::front() const {
	return *buffer;
}

template<class T>
T &Array<T>::back() const {
	return buffer[array_size - 1];
}

template<class T>
void Array<T>::push_back(const T &elem) {
	if (array_size >= array_capacity)
		reserve(array_capacity + REALLOC_INCREMENT);

	buffer[array_size++] = elem;
}

template<class T>
void Array<T>::pop_back() {
	if (array_size > 0)
		array_size--;
}

template<class T>
void Array<T>::reserve(unsigned int capacity) {
	if (capacity <= array_capacity)
		return;

	T *new_buffer = new T[capacity];
	for (unsigned int i = 0; i < array_capacity; i++)
		new_buffer[i] = buffer[i];

	delete[] buffer;
	buffer = new_buffer;
	array_capacity = capacity;
}

template<class T>
void Array<T>::shrink_to_fit() {
	if (array_capacity <= array_size)
		return;

	T *new_buffer = new T[array_size];
	for (unsigned int i = 0; i < array_capcity; i++)
		new_buffer[i] = buffer[i];

	delete[] buffer;
	buffer = new_buffer;
	array_capacity = array_size;
}

template<class T>
void Array<T>::resize(unsigned int size) {
	reserve(size);
	array_size = size;
}

template<class T>
void Array<T>::insert(unsigned int position, const T &value) {
	if (position > array_size) {
		std::out_of_range e("Array<T>::insert - position > size");
		throw e;
	}

	reserve(++array_size); //Make sure there's space to push everything up
	for (unsigned int i = array_size - 2; i >= position; i--) //Push everything up
		buffer[i + 1] = buffer[i];

	buffer[position] = value;
}

template<class T>
void Array<T>::clear() {
	array_size = 0;
	array_capacity = 0;
	delete[] buffer;
	buffer = nullptr;
}

template<class T>
Array<T>::~Array() {
	delete[] buffer;
}

template<class T>
unsigned int Array<T>::capacity() const {
	return array_capacity;
}

template<class T>
unsigned int Array<T>::size() const {
	return array_size;
}
