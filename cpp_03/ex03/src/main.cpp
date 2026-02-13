#include "DiamondTrap.hpp"

int	main(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Creating DiamondTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	DiamondTrap	diamond0;
    DiamondTrap	diamond1("DiamondOne");
    DiamondTrap	diamond3 = diamond1;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Attack Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	diamond0.attack("DiamondOne");			
    diamond1.attack("DiamondTwo");
    diamond3.attack("DiamondZero");

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Take Damage Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	diamond0.takeDamage(1);
    diamond1.takeDamage(3);
    diamond1.takeDamage(8); // This should reduce hit points to 0

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Be Repaired Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	diamond0.beRepaired(1);			
    diamond1.beRepaired(4); // Should not be possible, as DiamondOne has 0 hit points
    diamond3.beRepaired(5);
    
	std::cout	<< "-----------------------------------------" << std::endl
		<< "[ Testing Guard Gate]" << std::endl
		<< "-----------------------------------------" << std::endl;
	diamond0.guardGate();
	diamond1.guardGate();
	diamond3.guardGate();

	std::cout	<< "-----------------------------------------" << std::endl
		<< "[ Testing Hihg Five]" << std::endl
		<< "-----------------------------------------" << std::endl;
	diamond0.highFivesGuys();
	diamond1.highFivesGuys();
	diamond3.highFivesGuys();

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Who I am]" << std::endl
				<< "-----------------------------------------" << std::endl;
	diamond0.whoAmI();
	diamond1.whoAmI();
	diamond3.whoAmI();

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Draining Energy ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    for (int i = 0; i < 10; i++) {
        diamond3.attack("SOMEONE");
    }
    diamond3.attack("SOMEONE"); // Should not be possible, energy is 0
    diamond3.beRepaired(3); // Should not be possible, energy is 0
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Destroying DiamondTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    
	return (0);
}
