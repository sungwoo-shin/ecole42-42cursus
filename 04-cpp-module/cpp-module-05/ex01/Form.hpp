#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool _signed;

	Form(void);

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

	void beSigned(const Bureaucrat& b);

	const std::string& getName(void) const;
	const int& getSignGrade(void) const;
	const int& getExecGrade(void) const;
	const bool& getSigned(void) const;

	Form& operator=(const Form& f);
	Form(const Form& f);
	Form(const std::string& name,
		const int& sign_grade,
		const int& exec_grade);
	~Form(void);
};

std::ostream& operator<<(std::ostream& o, const Form& f);

#endif
