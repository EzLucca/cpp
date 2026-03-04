#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool	_issigned;
		const int _signedgrade;
		const int _executedgrade;

	public:
		Form(void);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		Form(std::string name, bool issigned, int signedgrade, int executedgrade);
		const std::string	getName() const;
		bool	getIssigned() const;
		int		getSignedGrade() const;
		int		getExecutedGrade() const;
		void	beSigned(Bureaucrat &corporate);
		void	signForm(Form const &form);

		class GradeTooHighException : public std::exception {
			public:
				const	char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const	char*	what() const throw();
		};

		class FormSigned : public std::exception {
			public:
				const	char*	what() const throw();
		};
};

std::ostream &operator<<(std::ostream &outstream, Form &f1);

#endif // FORM_HPP
