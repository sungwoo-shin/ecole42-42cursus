#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual void learnMateria(AMateria* am) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;

	virtual ~IMateriaSource(void) {}
};

#endif
