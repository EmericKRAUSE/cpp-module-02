#include "Fixed.hpp"

const int Fixed::_fractionBits = 8;

// ####################//
// Constructors & Destructors
Fixed::Fixed() : _fpNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const entier) : _fpNumber(entier * (1 << _fractionBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const flottant) : _fpNumber(roundf(flottant * (1 << _fractionBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// ####################//
// Operator Overload
Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_fpNumber = obj.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

bool operator>(const Fixed &l, const Fixed &r)
{
	return (l.getRawBits() > r.getRawBits());
}

bool operator<(const Fixed& l, const Fixed& r)
{
	return (l.getRawBits() < r.getRawBits());
}

bool operator>=(const Fixed &l, const Fixed &r)
{
	return (l.getRawBits() >= r.getRawBits());
}

bool operator<=(const Fixed &l, const Fixed &r)
{
	return (l.getRawBits() <= r.getRawBits());
}

bool operator==(const Fixed &l, const Fixed &r)
{
	return (l.getRawBits() == r.getRawBits());
}

bool operator!=(const Fixed &l, const Fixed &r)
{
	return (l.getRawBits() != r.getRawBits());
}

Fixed operator+(const Fixed &l, const Fixed &r)
{
	
	return (l.getRawBits() + r.getRawBits());
}

// ####################//
// Methodes
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fpNumber);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpNumber = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_fpNumber / (1 << _fractionBits));
}

int Fixed::toInt(void) const
{
	return (roundf(_fpNumber / (1 << _fractionBits)));
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}
