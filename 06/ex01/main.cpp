#include <iostream>
#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main()
{
	Data		raw_data;

	raw_data.num = 1;
	uintptr_t	serialized = serialize(&raw_data);
	Data		*deserialized = deserialize(serialized);

	std::cout << "raw_data         : " << &raw_data << std::endl;
	std::cout << "raw_data.num     : " << raw_data.num << std::endl;
	std::cout << "serialized       : 0x" << std::hex << serialized << std::endl;
	std::cout << "deserialized     : " << deserialized << std::endl;
	std::cout << "deserialized->num: " << deserialized->num << std::endl;
	return (0);
}
