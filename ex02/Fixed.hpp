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
		friend std::ostream&	operator<<(std::ostream& os, const Fixed& obj); // Require friend keyword because its using output stream which does not belong to Fixed class 
		// Comparison operators
		bool					operator>(const Fixed &r);
		bool					operator<(const Fixed& r);
		bool					operator>=(const Fixed &r);
		bool					operator<=(const Fixed &r);
		bool					operator==(const Fixed &r);
		bool					operator!=(const Fixed &r);
		// Arithmectic operators
		Fixed					operator+(const Fixed &r);
		Fixed					operator-(const Fixed &r);
		Fixed					operator*(const Fixed &r);
		Fixed					operator/(const Fixed &r);
		// Increment & Decrement operators
		Fixed&					operator++(void); // Pre-increment
		Fixed					operator++(int); // Post-increment
		Fixed&					operator--(void); // Pre-decrement
		Fixed					operator--(int); // Post-increment

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
