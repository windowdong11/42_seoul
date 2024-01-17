#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default_target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	: AForm(rhs.getName(), 145, 137), target(rhs.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this == &rhs)
		return (*this);
	target = rhs.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream out((target + "_shrubbery").c_str());
	if (!out.good())
		throw FileOpenException();
	out << "       _-_" << std::endl;
	out << "    /~~   ~~\\" << std::endl;
	out << " /~~ ASCII  ~~\\" << std::endl;
	out << "{        TREE   }" << std::endl;
	out << " \\  _-     -_  /" << std::endl;
	out << "   ~  \\\\ //  ~" << std::endl;
	out << "_- -   | | _- _" << std::endl;
	out << "  _ -  | |   -_" << std::endl;
	out << "      // \\\\" << std::endl;
	out << std::endl;
	out.close();
}
