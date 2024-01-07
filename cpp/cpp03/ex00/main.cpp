#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("Mario");

	ct.attack("Luigi"); //	hp : 20
	ct.takeDamage(1);		//	hp : 19
	ct.takeDamage(1);		//	hp : 18
	ct.takeDamage(1);		//	hp : 17
	ct.takeDamage(1);		//	hp : 16
	// action 5
	ct.takeDamage(1);		//	hp : 15
	ct.beRepaired(10);	//  hp : 25
	ct.takeDamage(26);	//	hp : 0 
	ct.takeDamage(1);		//	hp : 0 << cannot do anything
	ct.beRepaired(10);	//  hp : 0
	// action 10
	ct.beRepaired(10); 	//	hp : 0
	ClapTrap ct_for_action("Luigi");
	ct_for_action.beRepaired(1);
	ct_for_action.beRepaired(1);
	ct_for_action.beRepaired(1);
	ct_for_action.beRepaired(1);
	ct_for_action.beRepaired(1);
	// action 5
	ct_for_action.beRepaired(1);
	ct_for_action.beRepaired(1);
	ct_for_action.beRepaired(1);
	ct_for_action.beRepaired(1);
	ct_for_action.beRepaired(1);
	// action 10
	ct_for_action.attack("Can I attack?");
	return 0;
}