#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#define D_NAME		"Dog"

class Dog : public Animal
{
public:
	void makeSound(void) const;

	Dog& operator=(const Dog& d);
	Dog(void);
	Dog(const Dog& d);
	virtual ~Dog(void);
};

#endif
