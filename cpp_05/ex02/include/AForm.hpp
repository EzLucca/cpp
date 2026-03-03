#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool	_issigned;
		const int _signedgrade;
		const int _executedgrade;

	public:
		AForm(void);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm(void);

		AForm(std::string name, bool issigned, int signedgrade, int executedgrade);
		const std::string	getName() const;
		bool	getIssigned() const;
		int		getSignedGrade() const;
		int		getExecutedGrade() const;
		void	beSigned(Bureaucrat &corporate);

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
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &outstream, AForm &f1);

#endif // FORM_HPP
