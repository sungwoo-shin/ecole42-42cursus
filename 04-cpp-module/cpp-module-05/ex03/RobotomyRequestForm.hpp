#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "Form.hpp"

#define R_NAME		"RotobomyRequestForm"
#define R_FORM		"robotomy request"
#define R_SIGN		72
#define R_EXEC		45

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm(void);

public:
	void execute(const Bureaucrat& b) const;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& r);
	explicit RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& r);
	~RobotomyRequestForm(void);
};

#endif
