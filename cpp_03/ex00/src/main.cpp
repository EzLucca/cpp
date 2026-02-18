#include "ClapTrap.hpp"

int	main(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Creating ClapTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	ClapTrap	clap0;
    ClapTrap	clap1("ClapOne");
    ClapTrap	clap2("ClapTwo");
    ClapTrap	clap3 = clap1;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Attack Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	clap0.attack("ClapOne");			
    clap1.attack("ClapTwo");
    clap2.attack("ClapThree");
    clap3.attack("ClapZero");

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Take Damage Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	clap0.takeDamage(1);
    clap1.takeDamage(3);
    clap2.takeDamage(5);
    clap1.takeDamage(8); // This should reduce hit points to 0

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Be Repaired Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	clap0.beRepaired(1);			
    clap1.beRepaired(4); // Should not be possible, as ClapOne has 0 hit points
    clap2.beRepaired(2);
    clap3.beRepaired(5);
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Draining Energy ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    for (int i = 0; i < 10; i++) {
        clap3.attack("SOMEONE");
    }
    clap3.attack("SOMEONE"); // Should not be possible, energy is 0
    clap3.beRepaired(3); // Should not be possible, energy is 0
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Destroying ClapTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    
	return (0);
}
