#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

#define GRADE_MAX		1
#define GRADE_MIN		150

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

	Bureaucrat(void);

public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};

	int& incrementGrade(void);
	int& decrementGrade(void);

	const std::string& getName(void) const;
	const int& getGrade(void) const;

	Bureaucrat& operator=(const Bureaucrat& b);
	Bureaucrat(const Bureaucrat& b);
	Bureaucrat(const std::string& name, const int& grade);
	~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif
