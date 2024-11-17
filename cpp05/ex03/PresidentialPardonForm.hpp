#include "AForm.hpp"

class  PresidentialPardonForm: public AForm
{
	private:
		std::string target;
	public:
	 PresidentialPardonForm();
	 PresidentialPardonForm(std::string name);
	 PresidentialPardonForm(const PresidentialPardonForm &copy);
	 PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	 void execute(Bureaucrat const &exec)const ;
	 ~PresidentialPardonForm();
};