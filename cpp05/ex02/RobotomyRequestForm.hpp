#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class  RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
	 RobotomyRequestForm();
	 RobotomyRequestForm(std::string name);
	 RobotomyRequestForm(const  RobotomyRequestForm &copy);
	 RobotomyRequestForm &operator=( const RobotomyRequestForm &copy);
	void execute(Bureaucrat const &exec)const ;
	~ RobotomyRequestForm();
};
