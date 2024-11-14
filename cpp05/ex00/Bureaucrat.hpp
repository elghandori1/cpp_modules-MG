#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
		int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();
        class GradeTooHighException : public std::exception
        {
            public:
				        const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
				        const char* what() const throw();
        };
        std::string getName(void) const;
        int getGrade(void) const;
        void increment(void);
        void decrement(void);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bur);
 
#endif