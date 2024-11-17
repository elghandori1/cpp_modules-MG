#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bureaucra_1",20);
		ShrubberyCreationForm sh("Shrubbery");
		RobotomyRequestForm ro("Robert");
		PresidentialPardonForm pr("Presidential");

		sh.beSigned(b1);

		ro.beSigned(b1);

		pr.beSigned(b1);

		//--------------------

		b1.executeForm(sh);
		b1.executeForm(ro);
		b1.executeForm(pr);

		//--------------------

		std::cout << b1 <<std::endl;
		std::cout << sh <<std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}