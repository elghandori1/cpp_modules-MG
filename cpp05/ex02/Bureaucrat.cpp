#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
    grade = 10;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name), grade(copy.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if (this != &copy)
    {
        grade = copy.grade;
    }
    return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too Low!";
}

void Bureaucrat::increment()
{
    grade--;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
    grade++;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}

int Bureaucrat::getGrade() const
{
    return (grade);
}

std::string Bureaucrat::getName() const
{
    return (name);
}

void Bureaucrat::signForm(AForm const &sig)
{
	if (sig.isSigned())
		std::cout << name << " signed " << sig.getName() <<std::endl;
	else
		std::cout << name << " couldn't sign " << sig.getName() << "because " << grade <<"\n";
}

void Bureaucrat::executeForm(AForm const &form)
{
	try{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() <<std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << name << " couldn't execute " << form.getName() <<std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, Bureaucrat &bur)
{
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
    return (out);
}