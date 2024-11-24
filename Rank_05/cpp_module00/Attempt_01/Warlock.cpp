#include "Warlock.hpp"

//unused constructors / operators
Warlock::Warlock() {}

Warlock & Warlock::operator=(Warlock const & other)
{
	(void)this;
	(void)other;
	return (*this);
}

Warlock::Warlock(Warlock const & obj)
{
	*this = obj;
}

//used operators / constructors
Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(std::string name, std::string title): name(name), title(title)
{
	std::cout << name << ": This looks like another boring day" << std::endl;
}

std::string const & Warlock::getName() const
{
	return (this->name);
}

std::string const & Warlock::getTitle() const
{
	return (this->title);
}

void Warlock::setTitle(std::string const & str)
{
	this->title = str;
}

void Warlock::introduce() const
{
	std::cout << this->name <<": I am " << this->name << ", " << this->title << "!" << std::endl;
}
