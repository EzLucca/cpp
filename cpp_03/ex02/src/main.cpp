#include "FragTrap.hpp"

int	main(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Creating FragTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	FragTrap	frag0;
    FragTrap	frag1("FragOne");
    FragTrap	frag2("FragTwo");
    FragTrap	frag3 = frag1;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Attack Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	frag0.attack("FragOne");			
    frag1.attack("FragTwo");
    frag2.attack("FragThree");
    frag3.attack("FragZero");

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Take Damage Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	frag0.takeDamage(1);
    frag1.takeDamage(3);
    frag2.takeDamage(5);
    frag1.takeDamage(8); // This should reduce hit points to 0

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Be Repaired Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	frag0.beRepaired(1);			
    frag1.beRepaired(4); // Should not be possible, as FragOne has 0 hit points
    frag2.beRepaired(2);
    frag3.beRepaired(5);
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing High Five ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	frag0.highFivesGuys();
	frag1.highFivesGuys();
	frag2.highFivesGuys();
	frag3.highFivesGuys();

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Draining Energy ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    for (int i = 0; i < 10; i++) {
        frag3.attack("SOMEONE");
    }
    frag3.attack("SOMEONE"); // Should not be possible, energy is 0
    frag3.beRepaired(3); // Should not be possible, energy is 0
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Destroying FragTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    
	return (0);
}
