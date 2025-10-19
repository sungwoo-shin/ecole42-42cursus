#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private :
	int _fixed_point;
	static const int _frac_bits = 8;

public:
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed &operator=(const Fixed &f);
	Fixed(void);
	Fixed(const Fixed &f);
	~Fixed(void);
};

#endif

/*
** <Orthodox canonical form>
** At least one default constructor
** A copy contructor
** An assignation operator overload
** A destructor
*/
