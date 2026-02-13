#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}

void Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didin't put enought bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}

void Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {

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
	std::cout << "No level found. It should be DEBUG, INFO, WARNING OR ERROR.\n";
}
