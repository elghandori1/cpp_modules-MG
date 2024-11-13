#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(1){}

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

const char* Bureaucrat::GradeTooHighException::what() const 
{
    return "Grade is too High";
}

const char* Bureaucrat::GradeTooLowException::what() const 
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

int Bureaucrat::getGrade() const
{
    return (grade);
}

std::string Bureaucrat::getName() const
{
    return (name);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (out);
}
