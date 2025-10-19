#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	class NoMatchingTypeException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};

	Form* makeForm(const std::string& type, const std::string& name);

	Intern(void);
	Intern& operator=(const Intern& i);
	Intern(const Intern& i);
	~Intern(void);
};

#endif
