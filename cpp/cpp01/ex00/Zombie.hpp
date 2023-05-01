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

Zombie *newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChumb(std::string name)
{
	Zombie zombie(name);
}