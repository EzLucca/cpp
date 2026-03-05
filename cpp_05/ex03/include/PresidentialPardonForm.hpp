#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		const std::string getTarget() const;
		PresidentialPardonForm(const std::string target);
		void execute(Bureaucrat const & excutor) const override;
};

#endif // PRESIDENTIALPARDONFORM_HPP
