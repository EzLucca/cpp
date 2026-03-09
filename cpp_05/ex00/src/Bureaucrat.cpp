#include "Bureaucrat.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the Bureaucrat with a default type.
 */
Bureaucrat::Bureaucrat() : _name("Default name"), _grade(75) {
	std::cout << "Default constructor called\n";
}

/**
 * @brief Constructs a Bureaucrat with a given name and grade.
 * 
 * The name is set as a constant member. The grade must be in the range
 * 1 (highest) to 150 (lowest).
 *
 * @param name The name of the bureaucrat.
 * @param grade The initial grade of the bureaucrat.
 * @throws GradeTooHighException If the grade is less than 1.
 * @throws GradeTooLowException If the grade is greater than 150.
 */
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if(grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << name << " parameter constructor called\n";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new Bureaucrat by copying another one.
 *
 * @param other The Bureaucrat object to copy from.
 */
Bureaucrat::Bureaucrat(const Bureaucrat &other) 
	: _name(other._name),
	_grade(other._grade)
{
	std::cout << "Copy constructor called\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another Bureaucrat to this instance.
 *
 * @param other The Bureaucrat object to assign from.
 * @return Reference to the assigned Bureaucrat.
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if(this != &other) {
		_grade = other._grade;	
	}
	return *this;
}

/**
 * @brief Destructor.
 *
 * Called when the Bureaucrat object is destroyed.
 */
Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called\n";
}

const std::string	Bureaucrat::getName() const {
	return _name;
}

/**
 * @brief get Grade
 *
 * Get the private value of grade from the Bureaucrat object.
 *
 * @return integer _grade
 */
int		Bureaucrat::getGrade() const {
	return _grade;
}

/**
 * @brief increment Grade
 *
 * Check for exception else will increment the _grade from
 * Bureaucrat
 */
void	Bureaucrat::incrementGrade() {
	if(_grade <= 1)
		throw GradeTooHighException();
	else {
		_grade--;
		std::cout << "incrementing bureaucrat's grade" << std::endl;
	}
}

/**
 * @brief decrement Grade
 *
 * Check for exception else will decrement the _grade from
 * Bureaucrat
 */
void	Bureaucrat::decrementGrade() {
	if(_grade >= 150)
		throw GradeTooLowException();
	else {
		_grade++;
		std::cout << "decrementing bureaucrat's grade" << std::endl;
	}
}

/**
 * @brief sign the form
 *
 * will try to sign the form 
 *
 * @param form the form to be signed
 * @throw exception if can't sign it
 */
void	Bureaucrat::signForm(Form &form){

	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed form " << form.getName() << std::endl; 
	}
	catch(std::exception &e){
		std::cout << this->_name << " couldn't sign form "
			<< form.getName() << " because "
			<< e.what() << std::endl; 
	}
}

/**
 * @brief Returns a string describing the exception.
 * 
 * This function overrides std::exception::what() and provides a
 * descriptive message when a Bureaucrat's grade is too high.
 *
 * @return const char* A null-terminated string describing the exception.
 */
const	char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

/**
 * @brief Returns a string describing the exception.
 * 
 * This function overrides std::exception::what() and provides a
 * descriptive message when a Bureaucrat's grade is too low.
 *
 * @return const char* A null-terminated string describing the exception.
 */
const	char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

/**
 * @brief Overload of << operator for printing Bureaucrat private members.
 *
 * @param outstream The output stream.
 * @param corporate The Bureaucrat instance to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &outstream, Bureaucrat &corporate) {
	outstream << "Name: " << corporate.getName() << "\nBureaucrat grade: "
		<< corporate.getGrade() << "\n";
	return outstream;
}
