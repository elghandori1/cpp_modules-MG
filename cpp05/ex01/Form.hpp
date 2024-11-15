#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int g_to_sign;
		const int g_to_execute;
	public:
		Form();
		Form(std::string name, int a, int b);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
        ~Form();
		std::string getName() const;
		bool isSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		class GradeTooHighException: public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			const char* what() const throw();
		};
		void beSigned(Bureaucrat &bur);
};

std::ostream &operator<<(std::ostream &op,const Form &fro);
#endif