#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie(std::string name) : name(name) {}
		~Zombie() {
			std::cout << name << '\n';
		}
		void announce() {
			std::cout << name << '\n';
		}
};

Zombie* zombieHorde(int n, std::string name)
{
	Zombie *zombies = new Zombie[n]{};
}