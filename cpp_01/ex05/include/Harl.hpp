#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

/**
 * @brief Class representing a Harl who complains at different levels.
 *
 * Harl can complain at four levels: debug, info, warning, and error.
 * The complain method selects the appropriate message based on the level string.
 */
class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif // HARL_HPP
