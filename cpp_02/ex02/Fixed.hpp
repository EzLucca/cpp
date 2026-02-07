#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define MAX23BITS	8388607		
#define MIN23BITS	-8388608	

class Fixed {
	private:
		int _integer;
		static const int _fractionbits = 8;

	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		~Fixed();

		// Member function
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		// Comparison operators overload
		bool	operator > (const Fixed& other) const;
		bool	operator < (const Fixed& other) const;
		bool	operator >= (const Fixed& other) const;
		bool	operator <= (const Fixed& other) const;
		bool	operator == (const Fixed& other) const;
		bool	operator != (const Fixed& other) const;
		// Arithmetic operators overload
		Fixed& operator + (const Fixed& other) const;
		Fixed& operator - (const Fixed& other) const;
		Fixed& operator * (const Fixed& other) const;
		Fixed& operator / (const Fixed& other) const;
		// Increment/decremente operators overload
		Fixed& operator ++ (void);
		Fixed operator ++ (int);
		Fixed& operator -- (void);
		Fixed operator -- (int);
		// Static member function
		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& value);
#endif // FIXED_HPP
