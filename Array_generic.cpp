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

	Array();

	Array(unsigned int capacity);

	~Array();

	unsigned int capacity() const;

	unsigned int size() const;

	iterator begin() const;

	iterator end() const;

	T &front() const;

	T &back() const;

	void push_back(const T &elem);

	void pop_back();

	void reserve(unsigned int capacity);

	void resize(unsigned int size);

	T &operator[](unsigned int index) const;

	Array<T> &operator=(const Array<T> &);

	void insert(unsigned int position, const T &value);

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
Array<T> &Array<T>::operator=(const Array<T> &other) {
	reserve(other.capacity());
	for (unsigned int i = 0; i < other.size(); i++)
		buffer[i] = other[i];
	array_size = other.size();
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
		reserve(array_capacity + 10);

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
	if (buffer) { //Buffer remains uninitialised after default constructor
		for (unsigned int i = 0; i < array_capacity; i++)
			new_buffer[i] = buffer[i];

		delete[] buffer;
	}

	buffer = new_buffer;
	array_capacity = capacity;
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