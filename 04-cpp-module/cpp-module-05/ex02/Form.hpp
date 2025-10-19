#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <fstream>
#include <string>

#include "Bureaucrat.hpp"
#include "Random.hpp"

#define F_NAME		"Form"

class Form
{
private:
	const std::string _type;
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool _signed;

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

	class DoesNotSignedException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};

	class FileNotWorkingException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};

	void beSigned(const Bureaucrat& b);
	void check_executable(const Bureaucrat& b) const;
	virtual void execute(const Bureaucrat& b) const = 0;

	void setType(const std::string& type);

	const std::string& getType(void) const;
	const std::string& getName(void) const;
	const int& getSignGrade(void) const;
	const int& getExecGrade(void) const;
	const bool& getSigned(void) const;

	Form(void);
	Form& operator=(const Form& f);
	Form(const Form& f);
	Form(const std::string& name,
		const int& sign_grade,
		const int& exec_grade);
	virtual ~Form(void);
};

std::ostream& operator<<(std::ostream& o, const Form& f);

#endif
