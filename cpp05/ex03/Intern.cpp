#include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &intern)
{
    *this = intern;
}

Intern& Intern::operator=(const Intern &intern)
{
    (void)intern;
    return (*this);
}

Intern::~Intern(){}

const char *Intern::NotValid::what() const throw()
{
	 return "Form name is not valid!";
}

AForm *Intern::makeForm(std::string formName, std::string targetName)
{
	AForm *ptr = NULL;
	std::string arr[3]={"robotomy request", "shrubbery request", "presidential request"};
	int i = 0;

	while (arr[i] != formName)
		i++;

	switch (i)
	{
		case 0:
			ptr = new RobotomyRequestForm(targetName);
			std::cout << "Intern create Robotomy! "<<std::endl;
			break;
		case 1:
			ptr = new ShrubberyCreationForm(targetName);
			std::cout << "Intern create Shrubbery! "<<std::endl;
			break;
		case 2:
			ptr = new PresidentialPardonForm(targetName);
			std::cout << "Intern create Presidential! "<<std::endl;
			break;
		default:
			throw(NotValid());
			break;
	}
	return (ptr);
}
