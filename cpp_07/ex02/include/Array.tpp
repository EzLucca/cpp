#include "Array.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes an empty array with zero size.
 */
template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

/** 
 * @brief Parameterized constructor.
 * 
 * Initializes the array with the given number of default-initialized elements.
 *
 * @param size Number of elements to allocate.
 */
template <typename T>
Array<T>::Array(unsigned int size) : _array(nullptr), _size(size){
	if (_size > 0)
		_array = new T[_size]();
}

/** 
 * @brief Copy constructor.
 * 
 * Constructs a new Array by copying another Array.
 *
 * @param other Array object to copy from.
 */
template <typename T>
Array<T>::Array(const Array &other) : _array(nullptr), _size(other._size) {
	if (_size > 0) {
		_array = new T[_size]();
		for (std::size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another Array to this instance.
 *
 * @param other The Array object to assign from.
 * @return Reference to the assigned Array.
 */
template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other){
		delete[] _array;
		_size = other._size;
		if (_size > 0) {
			_array = new T[_size]();
			for (std::size_t i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
	}
	return *this;
}

/** 
 * @brief Destructor.
 * 
 * Releases the memory allocated for the array.
 */
template <typename T>
Array<T>::~Array(void) {
	delete[] _array;
}

/**
 * @brief Element access operator.
 * 
 * Provides access to the element at the given index.
 *
 * @param index Index of the element to access.
 * @throw std::out_of_range if index >= size().
 * @return Reference to the element at the given index.
 */
template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::out_of_range("Index is out of range");
	}
	return (_array[index]);
}

/**
 * @brief Get the number of elements in the array.
 * 
 * @return Number of elements in the array.
 */
template <typename T>
unsigned int	Array<T>::size() const { return _size; }
