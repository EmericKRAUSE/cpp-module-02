#include "Fixed.hpp"

const int Fixed::_fractionBits = 8;

// ####################//
// Constructors & Destructors
Fixed::Fixed() : _fpNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const entier) : _fpNumber(0)
{
	int scale = 1 << _fractionBits;

	if (entier > INT32_MAX / scale || entier < INT32_MIN / scale)
	{
		std::cout << "Error: " << entier << " is too big to fit in a int" << std::endl;
		return;
	}

	this->_fpNumber = entier * scale;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const flottant) : _fpNumber(0)
{

	int scale = 1 << _fractionBits;

	if (flottant > __FLT_MAX__ / scale || flottant < __FLT_MIN__ / scale)
	{
		std::cout << "Error: " << flottant << " is too big to fit in a float" << std::endl;
		return;
	}
	this->_fpNumber = roundf(flottant * (1 << _fractionBits));
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

// Comparison operators
bool Fixed::operator>(const Fixed &r)
{
	return (this->toFloat() > r.toFloat());
}

bool Fixed::operator<(const Fixed& r)
{
	return (this->toFloat() < r.toFloat());
}

bool Fixed::operator>=(const Fixed& r)
{
	return (this->toFloat() >= r.toFloat());
}

bool Fixed::operator<=(const Fixed& r)
{
	return (this->toFloat() <= r.toFloat());
}

bool Fixed::operator==(const Fixed& r)
{
	return (this->toFloat() == r.toFloat());
}

bool Fixed::operator!=(const Fixed& r)
{
	return (this->toFloat() != r.toFloat());
}

// Arithmectic operators
Fixed Fixed::operator+(const Fixed& r)
{
	return (Fixed(this->toFloat() + r.toFloat()));
}

Fixed Fixed::operator-(const Fixed& r)
{
	return (Fixed(this->toFloat() - r.toFloat()));
}

Fixed Fixed::operator*(const Fixed& r)
{
	return (Fixed(this->toFloat() * r.toFloat()));
}

Fixed Fixed::operator/( const Fixed& r)
{
	if (r.toFloat() == 0)
	{
		std::cerr << "Warning: division by 0" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / r.toFloat()));
}

// Increment & Decrement operators
Fixed& Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
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
