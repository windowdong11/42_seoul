#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "<try reference deleted pointer>" << std::endl;
	{
		Weapon *club = new Weapon("dead club");
		HumanA bob("Bob", *club);
		Weapon& ref = *club;
		
		std::cout << "club : " << club << std::endl;
		bob.attack();
		delete club;
		club = nullptr;

		int *dummy = new int[sizeof(Weapon) / sizeof(int) + 1];
		std::memset(dummy, 0, sizeof(Weapon) / sizeof(int) + 1);
		std::cout << "dummy : " << dummy << std::endl;
		ref.setType("try segfault");
		
		club = new Weapon("no");
		std::cout << "club : " << club << std::endl;
		bob.attack();
		delete club;
		club = nullptr;

		delete[] dummy;
	}
	return 0;
}