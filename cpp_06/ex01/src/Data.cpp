#include "Data.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the Data with a default type.
 */
Data::Data(void) {
		string1 = "this is the first string";
		string2 = "this is the second string";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new Data by copying another one.
 *
 * @param other The Data object to copy from.
 */
Data::Data(const Data &other) : 
	string1(other.string1),
	string2(other.string2)
{}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another Data to this instance.
 *
 * @param other The Data object to assign from.
 * @return Reference to the assigned Data.
 */
Data &Data::operator=(const Data &other) {
	if(this != &other) {
		string1 = other.string1;
		string2 = other.string2;
	}
	return *this;
}

/**
 * @brief Destructor.
 *
 * Called when the Data object is destroyed.
 */
Data::~Data(void) {}
