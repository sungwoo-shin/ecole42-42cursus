#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#define WC_NAME		"WrongCat"

class WrongCat : public WrongAnimal
{
public:
	void makeSound(void) const;

	WrongCat& operator=(const WrongCat& wc);
	WrongCat(void);
	WrongCat(const WrongCat& wc);
	virtual ~WrongCat(void);
};

#endif
