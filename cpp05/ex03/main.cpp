#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm* rrf = NULL;

	Bureaucrat B("Bureaucra_1", 10);

	try
	{
		Intern someRandomIntern;
		
		rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
		rrf->beSigned(B);
		B.executeForm(*rrf);
		delete  rrf;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		if (rrf != NULL) 
            delete rrf;
	}
	return (0);
}