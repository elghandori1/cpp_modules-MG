#include "Form.hpp"

Form::Form() :name("Default"), g_to_sign(1),g_to_execute(1)
{
	is_signed = false;
}

Form::Form(std::string name, int a, int b):name(name), g_to_sign(a), g_to_execute(b)
{
	is_signed = false;
	if (g_to_sign < 1  || g_to_execute < 1)
		throw (GradeTooHighException());
	else if (g_to_sign > 150 || g_to_execute > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &copy): name(copy.name), g_to_sign(copy.g_to_sign), g_to_execute(copy.g_to_execute)
{
	(*this) = copy;
}

Form &Form::operator=(const Form &copy)
{
	this->is_signed = copy.is_signed;
	return (*this);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too High!");
}

bool Form::getsigned() const
{
	return (is_signed);
}

std::string Form::getName() const
{
	return (name);
}

int Form::getGradeSign() const
{
	return (g_to_sign);
	}

int Form::getGradeExecute() const
{
	return (g_to_execute);
}

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= g_to_sign)
		is_signed = true;
	else
		throw(GradeTooLowException());
}

std::ostream &operator<<(std::ostream &op,const Form &fro){
	op << fro.getName() << fro.getsigned() << fro.getGradeSign() << fro.getGradeExecute() <<"\n";
	return (op);
}

Form::~Form(){}