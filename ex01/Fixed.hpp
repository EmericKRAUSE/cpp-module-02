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
		Fixed();
		Fixed(int const entier);
		Fixed(float const flottant);
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed &obj);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif
