#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat B1("mohamed", 1), B2("said", 4);

		Form f1("alex",2,140);

		f1.beSigned(B1);
		B1.signForm(f1);

		std::cout << B1 <<"\n";
		std::cout << B2 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
