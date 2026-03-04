#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;	

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm(const std::string target);
		const std::string getTarget() const;
		void	execute(Bureaucrat const & executor) const;
		class FileOpenException: public std::exception{
			public:
				const char* what() const throw();
		};
};

#endif // SHRUBBERYCREATIONFORM_HPP
