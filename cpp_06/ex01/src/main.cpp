#include "Serializer.hpp"

int main(void)
{
	try
	{
		Data* data1 = new Data();
		std::cout << "original strings: " << data1->string1
		<< " " << data1->string2 << " " << std::endl;
		std::cout << "address stored: " << data1 << "\n\n";

		uintptr_t rawuint = Serializer::serialize(data1);
		std::cout << "Raw serialized value (uintptr_t): " << rawuint << std::endl;
		std::cout << "serialized value as pointer: "
			<< reinterpret_cast<void*>(rawuint) << "\n\n";

		Data *data3 = Serializer::deserialize(rawuint);
		std::cout << "strings deserialized: " << data3->string1
		<< " " << data3->string2 << " " << std::endl;
		std::cout << "address stored: " << data3 << std::endl;
		delete data1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
