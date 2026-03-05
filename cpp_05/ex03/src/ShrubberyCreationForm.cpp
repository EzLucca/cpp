#include "../include/ShrubberyCreationForm.hpp"
// #include "ShrubberyCreationForm.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the ShrubberyCreationForm with a default type.
 */
ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", false, 145, 137),
	_target("default"){
		std::cout << "Default ShrubberyCreationForm Constructor called.\n";
	}

/**
 * @brief Parameterized constructor.
 *
 * Initializes the ShrubberyCreationForm with a target.
 *
 * @param target The target of the form.
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("ShrubberyCreationForm", false, 145, 137),
	_target(target){
		std::cout << target << " Constructor called.\n";
	}

/**
 * @brief Copy constructor.
 *
 * Creates a new ShrubberyCreationForm by copying another one.
 *
 * @param other The ShrubberyCreationForm object to copy from.
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm("ShrubberyCreationForm", false, 145, 137),
	_target(other._target){
		std::cout << "Copy Constructor called.\n";
	}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another ShrubberyCreationForm to this instance.
 *
 * @param other The ShrubberyCreationForm object to assign from.
 * @return Reference to the assigned ShrubberyCreationForm.
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
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
 * Called when the ShrubberyCreationForm object is destroyed.
 */
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "Shrubbery destructor called.\n";
}

const char* arvore = R"(
		                                             .
                                   .         ;  
      .              .              ;%     ;;   
        ,           ,                :;%  %;   
         :         ;                   :;%;'     .,   
,.        %;     %;            ;        %;'    ,;
  ;       ;%;  %%;        ,     %;    ;%;    ,%'
   %;       %;%;      ,  ;       %;  ;%;   ,%;' 
    ;%;      %;        ;%;        % ;%;  ,%;'
     `%;.     ;%;     %;'         `;%%;.%;'
      `:;%.    ;%%. %@;        %; ;@%;%'
         `:%;.  :;bd%;          %;@%;'
           `@%:.  :;%.         ;@@%;'   
             `@%.  `;@%.      ;@@%;         
               `@%%. `@%%    ;@@%;        
                 ;@%. :@%%  %@@%;       
                   %@bd%%%bd%%:;     
                     #@%%%%%:;;
                     %@@%%%::;
                     %@@@%(o);  . '         
                     %@@@o%;:(.,'         
                 `.. %@@@o%::;         
                    `)@@@o%::;         
                     %@@(o)::;        
                    .%@@@@%::;         
                    ;%@@@@%::;.          
                   ;%@@@@%%:;;;. 
               ...;%@@@@@%%:;;;;,..
			   )";

/**
 * @brief Getter.
 *
 * Get the target of the object class.
 * @return the _target
 */
const std::string ShrubberyCreationForm::getTarget() const { return _target; };

/**
 * @brief Creates a file containing ASCII art of a shrubbery.
 *
 * @param executor Bureaucrat executing the form.
 * @throw FormSigned if form is not signed.
 * @throw GradeTooLowException if executor grade is too low.
 * @throw FileOpenException if file creation fails.
 */
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if(!this->getIssigned())
		throw FormNotSigned();
	if(executor.getGrade() > this->getExecutedGrade())
		throw GradeTooLowException();
	std::ofstream out;
	out.open(this->_target + "_shrubbery");
	if(out.fail()) {
		throw ShrubberyCreationForm::FileOpenException();
	}
	out << arvore;
	out.close();
};

/**
 * @brief Returns a string describing the exception.
 * 
 * This function overrides std::exception::what() and provides a
 * descriptive message of the error.
 *
 * @return const char* A null-terminated string describing the exception.
 */
const char* ShrubberyCreationForm::FileOpenException::what() const throw(){
	return "file could not be opened";
}
