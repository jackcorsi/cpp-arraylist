template <class T>

class Array {
private:
	unsigned int array_size;
	unsigned int array_capacity;
	T *buffer;

public:
	typedef T * iterator;

	Array();
	Array(unsigned int capacity);
	~Array();

	unsigned int capacity();
	unsigned int size();
	iterator begin();
	iterator end();
	T & front();
	T & back();
	void push_back(const T & value);
	void pop_back();

	void reserve(unsigned int capacity);
	void resize(unsigned int size);

	T & operator[](unsigned int index);
	Array <T> & operator=(const Array <T> &);
	void insert(unsigned int position, T value);

	void clear();
};

Array::Array() {
	array_capacity = 0;
	array_size = 0;
	buffer = nullptr;
}

Array::Array(unsigned int capacity) {
	array_capacity = size;
	array_size = 0;
	buffer = (T *) malloc(sizeof(T) * array_capacity);
	if (buffer == NULL)
	{
		std::bad_alloc e;
		throw e;
	}

	for (int i = 0; i < array_capacity; i++)
		new (buffer + i) T;
}

Array & Array::operator=(const Array <T> & other) {
	//TODO
}

T & Array::operator[](unsigned int index) {
	return buffer[index];
}

Array<T>::iterator Array::begin() {
	return buffer;
}

Array<T>::iterator Array::end() {
	return buffer + array_size - 1;
}

T & Array::front() {
	return buffer;
}

T & Array::back() {
	return buffer[array_size - 1];
}

void Array::push_back(const T & elem) {
	if (array_size >= array_capacity)
		reserve(array_capacity + 10);

	buffer[array_size++] = elem;
}

void Array::pop_back() {
	if (array_size > 0)
		array_size--;
}

void Array::reserve() {

}