#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int g_to_sign;
		const int g_to_execute;
	public:
		AForm();
		AForm(std::string name, int a, int b);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
        virtual ~AForm();
		std::string getName() const;
		bool isSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		void beSigned(Bureaucrat &bur);
		virtual void    execute(Bureaucrat const & exec) const = 0;
};

std::ostream &operator<<(std::ostream &op,const AForm &form);
#endif