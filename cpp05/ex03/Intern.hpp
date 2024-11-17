#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
    public:
		Intern(void);
		Intern(const Intern &intern);
		~Intern();
		Intern& operator=(const Intern &intern);
		AForm *makeForm( std::string formName, std::string targetName);
        class NotValid:public std::exception
		{
			public:
				const char* what() const throw();
		};
};
#endif