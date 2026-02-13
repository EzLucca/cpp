
#include "ScavTrap.hpp"

int	main(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Creating ScavTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	ScavTrap	scav0;
    ScavTrap	scav1("ScavOne");
    ScavTrap	scav2("ScavTwo");
    ScavTrap	scav3 = scav1;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Attack Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	scav0.attack("ScavOne");			
    scav1.attack("ScavTwo");
    scav2.attack("ScavThree");
    scav3.attack("ScavZero");

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Take Damage Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	scav0.takeDamage(1);
    scav1.takeDamage(3);
    scav2.takeDamage(5);
    scav1.takeDamage(8); // This should reduce hit points to 0

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Be Repaired Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	scav0.beRepaired(1);			
    scav1.beRepaired(4); // Should not be possible, as ScavOne has 0 hit points
    scav2.beRepaired(2);
    scav3.beRepaired(5);
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Guard Gate Mode ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	scav0.guardGate();
	scav1.guardGate();
	scav2.guardGate();
	scav3.guardGate();

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Draining Energy ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    for (int i = 0; i < 10; i++) {
        scav3.attack("SOMEONE");
    }
    scav3.attack("SOMEONE"); // Should not be possible, energy is 0
    scav3.beRepaired(3); // Should not be possible, energy is 0
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Destroying ScavTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    
	return (0);
}
