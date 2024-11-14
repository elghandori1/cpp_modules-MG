#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45)
{
    this->target ="Default";	
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm("Robotomy", 72, 45)
{
	this->target = name;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :AForm(copy)
{
	*this =  copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{ 
		AForm::operator=(copy);
	    target = copy.target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &exec) const
{
    if (!this->getsigned()){
        throw AForm::GradeTooLowException();
	}

    if (exec.getGrade() > this->getGradeExecute()){
    	throw AForm::GradeTooLowException();
	}
	std::srand(std::time(NULL));
	if (std::rand()%2 == 0)
	{
		std::cout << target << " has been robotomized successfully! " <<std::endl;
	}
	else{
		std::cout << target << "  the robotomy failed. " <<std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm(){}