#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "Form.hpp"

#define P_NAME		"PresidentialPardonForm"
#define P_SIGN		25
#define P_EXEC		5

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm(void);

public:
	void execute(const Bureaucrat& b) const;

	PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
	explicit PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& p);
	~PresidentialPardonForm(void);
};

#endif
