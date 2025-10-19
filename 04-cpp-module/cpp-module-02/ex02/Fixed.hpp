#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
private :
	int _fixed_point;
	static const int _frac_bits = 8;

public :
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed *fmin(Fixed *lhs, Fixed *rhs);
	static Fixed *fmax(Fixed *lhs, Fixed *rhs);
	static const Fixed &fmin(const Fixed &lhs, const Fixed &rhs);
	static const Fixed &fmax(const Fixed &lhs, const Fixed &rhs);

	bool operator>(const Fixed &f);
	bool operator<(const Fixed &f);
	bool operator>=(const Fixed &f);
	bool operator<=(const Fixed &f);
	bool operator==(const Fixed &f);
	bool operator!=(const Fixed &f);

	Fixed operator+(const Fixed &f);
	Fixed operator-(const Fixed &f);
	Fixed operator*(const Fixed &f);
	Fixed operator/(const Fixed &f);

	Fixed operator++(int);
	Fixed operator--(int);
	Fixed &operator++(void);
	Fixed &operator--(void);

	Fixed &operator=(const Fixed &f);

	Fixed(void);
	explicit Fixed(const int v);
	explicit Fixed(const float v);
	Fixed(const Fixed &f);
	~Fixed(void);
};

std::ostream &operator<<(std::ostream &o, const Fixed &f);

#endif
