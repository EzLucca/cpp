#include "PresidentialPardonForm.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the PresidentialPardonForm with a default type.
 */
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", false, 25, 5),
	_target("default"){
		std::cout << "Default PresidentialPardonForm Constructor called.\n";
	}

/**
 * @brief Parameterized constructor.
 *
 * Initializes the RobotomyRequestForm with a target.
 *
 * @param target The target of the form.
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm("PresidentialPardonForm", false, 25, 5),
	_target(target){
		std::cout << target << " Constructor called.\n";
	}

/**
 * @brief Copy constructor.
 *
 * Creates a new PresidentialPardonForm by copying another one.
 *
 * @param other The PresidentialPardonForm object to copy from.
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm("PresidentialPardonForm", false, 25, 5),
	_target(other._target){
		std::cout << " Copy Constructor called.\n";
	}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another PresidentialPardonForm to this instance.
 *
 * @param other The PresidentialPardonForm object to assign from.
 * @return Reference to the assigned PresidentialPardonForm.
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if(this != &other) {
		_target = other._target;
		AForm::operator=(other);
	}
	std::cout << "Copy assignment operator called.\n";
	return *this;
}


/**
 * @brief Destructor.
 *
 * Called when the PresidentialPardonForm object is destroyed.
 */
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential destructor called.\n";
}

/**
 * @brief Getter.
 *
 * Get the target of the object class.
 * @return the _target
 */
const std::string PresidentialPardonForm::getTarget() const { return _target; };

/**
 * @brief Executes the presidential pardon.
 * @param executor Bureaucrat executing the form.
 * @throws FormNotSigned if the form is not signed.
 * @throws GradeTooLowException if the executor grade is too low.
 */
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if(!this->getIssigned())
		throw FormNotSigned();
	if(executor.getGrade() > this->getExecutedGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
