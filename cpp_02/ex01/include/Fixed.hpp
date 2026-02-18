#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define MAX23BITS	8388607		
#define MIN23BITS	-8388608	

/**
 * @brief Class representing a fixed-point number.
 *
 * Stores a fixed-point value internally as an integer with a fixed number
 * of fractional bits. Provides constructors for int and float, as well as
 * methods to convert back to float or int.
 */
class Fixed {
	private:
		int _integer;
		static const int _fractionbits = 8;

	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float almostreal);
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);
#endif // FIXED_HPP
