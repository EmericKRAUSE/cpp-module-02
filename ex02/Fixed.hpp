#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fpNumber;
		static const int _fractionBits;

	public:
		// ####################//
		// Constructors & Destructors
		Fixed();
		Fixed(int const entier);
		Fixed(float const flottant);
		Fixed(const Fixed& other);
		~Fixed();

		// ####################//
		// Operator Overload
		Fixed&					operator=(const Fixed& obj);
		friend std::ostream&	operator<<(std::ostream& os, const Fixed& obj);
		friend bool				operator>(const Fixed &l, const Fixed &r);
		friend bool				operator<(const Fixed& l, const Fixed& r);
		friend bool				operator>=(const Fixed &l, const Fixed &r);
		friend bool				operator<=(const Fixed &l, const Fixed &r);
		friend bool				operator==(const Fixed &l, const Fixed &r);
		friend bool				operator!=(const Fixed &l, const Fixed &r);
		friend Fixed			operator+(const Fixed &l, const Fixed &r);

		// ####################//
		// Methodes
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b); // Overloading min function
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b); // Overloading max function

};

#endif
