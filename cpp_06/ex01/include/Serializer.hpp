#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>
#include "Data.hpp"

class Data;
class Serializer {
	private:

	public:
		Serializer(void) = delete;
		Serializer(const Serializer &other) = delete;
		Serializer &operator=(const Serializer &other) = delete;
		~Serializer(void) = delete;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
