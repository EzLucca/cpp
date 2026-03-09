#include "../include/AForm.hpp"
// #include "AForm.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the AForm with a default type.
 */
AForm::AForm() : 
	_name("default"),
	_issigned(false),
	_signgrade(75),
	_executegrade(75)
{}

/**
 * @brief Copy constructor.
 *
 * Creates a new AForm by copying another one.
 *
 * @param other The AForm object to copy from.
 */
AForm::AForm(const AForm &other) :
	_name(other._name),
	_issigned(other._issigned),
	_signgrade(other._signgrade),
	_executegrade(other._executegrade)
{}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another AForm to this instance.
 *
 * @param other The AForm object to assign from.
 * @return Reference to the assigned AForm.
 */
AForm &AForm::operator=(const AForm &other) {
	if(this != &other){
		_issigned = other._issigned;
	}
	return *this;
}

/**
 * @brief Destructor.
 *
 * Called when the AForm object is destroyed.
 */
AForm::~AForm() {}

/**
 * @brief Constructs a AForm object with the specified parameters.
 *
 * Initializes a AForm with a given name, signed status, required grade to sign,
 * and required grade to execute.
 *
 * @param name The name of the form.
 * @param issigned The initial signed status of the form (true if signed, false otherwise).
 * @param signedgrade The grade required to sign the form (must be between 1 and 150).
 * @param executedgrade The grade required to execute the form (must be between 1 and 150).
 *
 * @throw GradeTooHighException Thrown if either signedgrade or executedgrade is less than 1.
 * @throw GradeTooLowException Thrown if either signedgrade or executedgrade is greater than 150.
 */
AForm::AForm(std::string name, bool issigned, int signgrade, int executegrade) :
	_name(name),
	_issigned(issigned),
	_signgrade(signgrade),
	_executegrade(executegrade)
{
	if(this->_issigned) 
		throw std::invalid_argument("Form cannot be initiated already signed");
	if(signgrade < 1 || executegrade < 1)
		throw GradeTooHighException();
	else if (signgrade > 150 || executegrade > 150)
		throw GradeTooLowException();
}

/**
 * @brief get _name
 *
 * Get the private value of _name from the AForm object.
 *
 * @return string _name
 */
const std::string	AForm::getName() const {return _name;};

/**
 * @brief get _issigned
 *
 * Get the private value of _issigned from the AForm object.
 *
 * @return bool _issigned
 */
bool	AForm::getIssigned() const {return _issigned;};

/**
 * @brief get _signgrade
 *
 * Get the private value of _signgrade from the AForm object.
 *
 * @return integer _signgrade
 */
int		AForm::getSignedGrade() const {return _signgrade;};

/**
 * @brief get _executegrade
 *
 * Get the private value of _executegrade from the AForm object.
 *
 * @return integer _executegrade
 */
int		AForm::getExecutedGrade() const {return _executegrade;};

/**
 * @brief Attempts to sign the form with the given Bureaucrat.
 *
 * This function allows a Bureaucrat to sign the form if:
 * - The form is not already signed.
 * - The Bureaucrat's grade is sufficient (less than or equal to _signgrade).
 *
 * @param corporate The Bureaucrat attempting to sign the form.
 *
 * @throw FormSigned Thrown if the form is already signed.
 * @throw GradeTooLowException Thrown if the Bureaucrat's grade is too low to sign the form.
 */
void	AForm::beSigned(Bureaucrat &corporate) {
	if(this->_issigned) {
		throw FormSigned();
	}
	if(corporate.getGrade() > this->_signgrade){
		throw GradeTooLowException();
	}
	this->_issigned = true;
}

/**
 * @brief Returns a string describing the exception.
 * 
 * This function overrides std::exception::what() and provides a
 * descriptive message when a AForm's grade is too high.
 *
 * @return const char* A null-terminated string describing the exception.
 */
const char* AForm::GradeTooHighException::what() const throw(){
	return "the grade is too high";
}

/**
 * @brief Returns a string describing the exception.
 * 
 * This function overrides std::exception::what() and provides a
 * descriptive message when a AForm's grade is too low.
 *
 * @return const char* A null-terminated string describing the exception.
 */
const char* AForm::GradeTooLowException::what() const throw(){
	return "the grade is too low";
}

/**
 * @brief Returns a string describing the exception.
 * 
 * This function overrides std::exception::what() and provides a
 * descriptive message when a AForm is already signed.
 *
 * @return const char* A null-terminated string describing the exception.
 */
const char* AForm::FormSigned::what() const throw(){
	return "the form was previously signed";
}

/**
 * @brief Returns a string describing the exception.
 * 
 * This function overrides std::exception::what() and provides a
 * descriptive message when a AForm is not signed.
 *
 * @return const char* A null-terminated string describing the exception.
 */
const char* AForm::FormNotSigned::what() const throw(){
	return "the form was not signed";
}
/**
 * @brief Overload of << operator for printing AForm private members.
 *
 * @param outstream The output stream.
 * @param form1 The AForm instance to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &outstream, AForm &form1){
	outstream << "form name: " << form1.getName()
		<< "\nsignature state: " << form1.getIssigned() 
		<< "\nsigning grade: " << form1.getSignedGrade()
		<< "\nexecution grade: " << form1.getExecutedGrade() << "\n"; 
	return outstream;
}
