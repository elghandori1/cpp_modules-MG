#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137)
{
	this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :AForm(copy)
{
	*this =  copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) { 
    if (this != &copy)
    {
        AForm::operator=(copy);
        target = copy.target; 
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &exec) const {
    if (!this->isSigned()) {
        throw AForm::GradeTooLowException();
    }
    if (exec.getGrade() > this->getGradeExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::ofstream	outfile;
    std::string file = target + "_Shrubbery";
    outfile.open(file.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Failed to open file " <<target + "_shrubbery" << "\n";
        return;
    }
    outfile << "      ccee88oo\n"
         << "  C8O8O8Q8PoOb o8oo\n"
         << " dOB69QO8PdUOpugoO9bD\n"
         << "CgggbU8OU qOp qOdoUOdcb\n"
         << "    6OuU  /p u gcoUodpP\n"
         << "      \\\\//  /douUP\n"
         << "        \\\\////\n"
         << "         |||/\\\n"
         << "         |||\\/\n"
         << "         |||||\n"
         << "   .....//||||....\n";

    outfile.close();
}