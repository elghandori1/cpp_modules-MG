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
    if (this != &copy) {
        grade = copy.grade;
    }
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too Low";
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

int Bureaucrat::getGrade() 
{
    return (grade);
}

std::string Bureaucrat::getName() 
{
    return (name);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat &bur)
{
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
    return (out);
}