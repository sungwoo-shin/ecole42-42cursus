#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iomanip>
#include <iostream>

#define W_SIZE		40
#define AM_SIZE		4

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	const std::string& getType(void) const;

	virtual AMateria* clone(void) const = 0;
	virtual void use(const ICharacter& ic);

	AMateria& operator=(const AMateria& am);
	AMateria(void);
	explicit AMateria(const std::string& type);
	AMateria(const AMateria& am);
	virtual ~AMateria(void);
};

#endif
