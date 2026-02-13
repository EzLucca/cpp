#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string name);
		~Weapon();
		const std::string &getType() const;
		void	setType(std::string type);
};

#endif // WEAPON_HPP
