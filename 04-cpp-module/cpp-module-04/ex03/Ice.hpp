#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"

#define I_NAME		"ice"

class Ice : public AMateria
{
public:
	AMateria* clone(void) const;
	void use(const ICharacter& ic);

	Ice& operator=(const Ice& i);
	Ice(void);
	explicit Ice(const std::string& type);
	Ice(const Ice& i);
	virtual ~Ice(void);
};

#endif
