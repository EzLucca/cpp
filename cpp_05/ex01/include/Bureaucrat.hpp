#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
class Bureaucrat {
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		Bureaucrat(std::string name, int grade);
		const std::string	getName() const;
		int		getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &form);

		class GradeTooHighException : public std::exception {
			public:
				const	char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const	char*	what() const throw();
		};
};

std::ostream &operator<<(std::ostream &outstream, Bureaucrat &corporate);
#endif // BUREAUCRAT_HPP
