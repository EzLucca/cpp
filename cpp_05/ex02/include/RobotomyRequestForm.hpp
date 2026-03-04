#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(const std::string name);
		const std::string getTarget() const;
		void execute(Bureaucrat const & excutor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
