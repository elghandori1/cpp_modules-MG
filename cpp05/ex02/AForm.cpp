#include "AForm.hpp"

AForm::AForm() :name("Default"), g_to_sign(10),g_to_execute(10)
{
	is_signed = false;
	if (g_to_sign < 1  || g_to_execute < 1)
		throw (GradeTooHighException());
	else if (g_to_sign > 150 || g_to_execute > 150)
		throw (GradeTooLowException());
}

AForm::AForm(std::string name, int a, int b):name(name), g_to_sign(a), g_to_execute(b)
{
	is_signed = false;
	if (g_to_sign < 1  || g_to_execute < 1)
		throw (GradeTooHighException());
	else if (g_to_sign > 150 || g_to_execute > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &copy): name(copy.name), g_to_sign(copy.g_to_sign), g_to_execute(copy.g_to_execute)
{
	(*this) = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	this->is_signed = copy.is_signed;
	return (*this);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too High!");
}

bool AForm::isSigned() const
{
	return (is_signed);
}

std::string AForm::getName() const
{
	return (name);
}

int AForm::getGradeSign() const
{
	return (g_to_sign);
	}

int AForm::getGradeExecute() const
{
	return (g_to_execute);
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= g_to_sign)
		is_signed = true;
	else
		throw(GradeTooLowException());
}

AForm::~AForm(){}

std::ostream &operator<<(std::ostream &op,const AForm &fro){
	op << fro.getName() << "-" <<fro.isSigned()<< "-" << fro.getGradeSign()<< "-" << fro.getGradeExecute();
	return (op);
}

