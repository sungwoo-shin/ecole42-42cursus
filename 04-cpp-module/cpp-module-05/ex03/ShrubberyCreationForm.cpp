#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	check_executable(b);
	std::ofstream ofs("<" + getName() + ">_shrubbery");
	if (!ofs.good())
		throw FileNotWorkingException();
	std::string shrubbery = "               ,@@@@@@@,\n"
							"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
							"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
							"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
							"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
							"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
							"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
							"       |o|        | |         | |\n"
							"       |.|        | |         | |\n"
							"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
	ofs << shrubbery;
	ofs.close();
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	return (*(dynamic_cast<ShrubberyCreationForm*>(&(Form::operator=(s)))));
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form()
{
	setType(S_NAME);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form(target, S_SIGN, S_EXEC)
{
	setType(S_NAME);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
	: Form(s)
{
	setType(S_NAME);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
