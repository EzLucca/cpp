#include "Intern.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the Intern with a default type.
 */
Intern::Intern(void) {
	std::cout << "Intern default constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new Intern by copying another one.
 *
 * @param other The Intern object to copy from.
 */
Intern::Intern(const Intern &other) {
	(void) other;
	std::cout << "Intern copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another Intern to this instance.
 *
 * @param other The Intern object to assign from.
 * @return Reference to the assigned Intern.
 */
Intern &Intern::operator=(const Intern &other) {
	(void) other;
	std::cout << "Intern copy assign operator.\n";
	return *this;
}

/**
 * @brief Destructor.
 *
 * Called when the Intern object is destroyed.
 */
Intern::~Intern() {
	std::cout << "Intern destructor is called.\n";
}

/**
 * @brief Creates a form based on the given name.
 *
 * The intern matches the form name with the available forms and
 * returns a newly allocated instance targeting `formTarget`.
 *
 * @param formName Name of the form to create.
 * @param formTarget Target of the form.
 * @return Pointer to the created form, or nullptr if the name is invalid.
 */
AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) {

	int	requestedForm = -1;
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0;i < 3;i++) {
		if(names[i] == formName){
			requestedForm = i;	
			break;
		}
	}
	switch(requestedForm) {
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(formTarget);
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(formTarget);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(formTarget);
		default:
			std::cout << "Intern couldn't create the form, name doesn't exist\n";
			return nullptr;
	}
}
