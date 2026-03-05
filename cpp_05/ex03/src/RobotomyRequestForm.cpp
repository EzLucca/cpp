#include "RobotomyRequestForm.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the RobotomyRequestForm with a default type.
 */
RobotomyRequestForm::RobotomyRequestForm(void) : 
	AForm("RobotomyRequestForm", false, 72, 45),
	_target("default"){
		std::cout << "Default RobotomyRequestForm Constructor called.\n";
	}

/**
 * @brief Parameterized constructor.
 *
 * Initializes the RobotomyRequestForm with a target.
 *
 * @param target The target of the form.
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("RobotomyRequestForm", false, 72, 45),
	_target(target){
		std::cout << target << " Constructor called.\n";
	}

/**
 * @brief Copy constructor.
 *
 * Creates a new RobotomyRequestForm by copying another one.
 *
 * @param other The RobotomyRequestForm object to copy from.
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm("RobotomyRequestForm", false, 72, 45),
	_target(other._target){
		std::cout << " Copy Constructor called.\n";
	}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another RobotomyRequestForm to this instance.
 *
 * @param other The RobotomyRequestForm object to assign from.
 * @return Reference to the assigned RobotomyRequestForm.
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if(this != &other) {
		_target = other._target;
		AForm::operator=(other); // why
	}
	std::cout << "Copy assignment operator called.\n";
	return *this;
}


/**
 * @brief Destructor.
 *
 * Called when the RobotomyRequestForm object is destroyed.
 */
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy destructor called.\n";
}

/**
 * @brief Getter.
 *
 * Get the target of the object class.
 * @return the _target
 */
const std::string RobotomyRequestForm::getTarget() const { return _target; };

/**
 * @brief Executes the robotomy request.
 * @param executor Bureaucrat executing the form.
 * @throws FormNotSigned if the form is not signed.
 * @throws GradeTooLowException if the executor grade is too low.
 */
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if(!this->getIssigned())
		throw FormNotSigned();
	if(executor.getGrade() > this->getExecutedGrade())
		throw GradeTooLowException();
	std::cout << "Drilling noises ....\n";
	if (rand() %2 == 0)
		std::cout << _target << " has been robotomized\n";
	else
		std::cout << _target << " robotomy failed\n";
}
