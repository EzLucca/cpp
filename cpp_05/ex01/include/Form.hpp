#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form {
	private:
		const std::string _name;
		bool	_signed;
		const int _signedgrade;
		const int _executedgrade;

	public:
		Form(void);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		const std::string	getName() const;
		int		getSignedGrade() const;
		int		getExecutedGrade() const;
		bool	getSigned() const;

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

#endif // FORM_HPP
