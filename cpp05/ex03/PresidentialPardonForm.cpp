#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5)
{
	this->target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm("Presidential", 25, 5)
{
	this->target = name;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :AForm(copy)
{
	*this =  copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
     if (this != &copy)
     {
        AForm::operator=(copy);
        target = copy.target;
     }
      return *this; 
}

void PresidentialPardonForm::execute(Bureaucrat const &exec) const
{
    if (!this->isSigned()) 
        throw AForm::GradeTooLowException();

    if (exec.getGrade() > this->getGradeExecute()) 
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){}