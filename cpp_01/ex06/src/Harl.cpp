#include "Harl.hpp"

/**
 * @brief Constructor.
 *
 * Initializes the Harl instance.
 */
Harl::Harl() {}

/**
 * @brief Destructor.
 *
 * Cleans up the Harl instance.
 */
Harl::~Harl() {}

/**
 * @brief Prints a debug-level message.
 *
 * This is the lowest level of complaint, often humorous or trivial.
 */
void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}

/**
 * @brief Prints an info-level message.
 *
 * Expresses mild annoyance, usually about mistakes or unexpected costs.
 */
void	Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

/**
 * @brief Prints a warning-level message.
 *
 * Expresses stronger dissatisfaction, claiming entitlement or expectation.
 */
void	Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years, whereas you started working here just last month.\n";
}

/**
 * @brief Prints an error-level message.
 *
 * The highest level of complaint, demanding immediate attention from management.
 */
void	Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

/**
 * @brief Makes Harl complain at a specified level.
 *
 * Selects and calls the appropriate private method based on the level string.
 * Acceptable levels are: "DEBUG", "INFO", "WARNING", "ERROR".
 * If the level is not recognized, prints a warning message.
 *
 * @param level The level of the complaint.
 */
void	Harl::complain(std::string level) {

	std::string input[] { "DEBUG", "INFO", "WARNING", "ERROR" };

	using HarlFunc = void (Harl::*)();

	HarlFunc funcs[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (input[i] == level) {
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}
