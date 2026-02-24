#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string	getName() const;
		int		getGrade() const;
		void	incrementGrade() const;
		void	decrementGrade() const;
};

#endif // BUREAUCRAT_HPP
