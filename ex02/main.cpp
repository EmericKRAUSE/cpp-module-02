#include <iostream> 
#include "Fixed.hpp"

int main(void)
{
	Fixed a(4);
	Fixed b(5);
	std::cout << (a < b) << std::endl;
	return 0;
}