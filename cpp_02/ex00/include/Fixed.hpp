#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/**
 * @brief Class representing a fixed-point number.
 *
 * Stores a fixed-point value internally as an integer with a fixed number
 * of fractional bits. Provides access to the raw value and supports copying.
 */
class Fixed {
	private:
		int _integer;
		static const int _fraction = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif // FIXED_HPP
