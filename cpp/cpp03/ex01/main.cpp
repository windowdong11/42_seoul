#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Mario");

	scav.guardGate();
	scav.takeDamage(3);
	scav.attack("Luigi"); //	hp : 20
	scav.beRepaired(3);
	ScavTrap copied_scav;
	copied_scav = scav;
	ScavTrap ct_for_action("Luigi");
	ct_for_action.attack("test");
	ct_for_action.attack("test");
	ct_for_action.attack("test");
	ct_for_action.attack("test");
	ct_for_action.attack("test");
	// action 5
	ct_for_action.attack("test");
	ct_for_action.attack("test");
	ct_for_action.attack("test");
	ct_for_action.attack("test");
	ct_for_action.attack("test");
	// action 10
	ct_for_action.attack("Can I attack?");
	return 0;
}