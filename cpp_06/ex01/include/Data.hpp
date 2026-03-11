#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	private:

	public:
		Data(void);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data(void);

		std::string string1;
		std::string string2;
};

#endif // DATA_HPP
