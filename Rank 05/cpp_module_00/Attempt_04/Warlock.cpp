#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock & Warlock::operator=(Warlock const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_title = other._title;
	}
	return (*this);
}

Warlock::Warlock(Warlock const &other)
{
	*this = other;
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job is done!" << std::endl;
}

const std::string Warlock::getName() const
{
	return (this->_name);
}

const std::string Warlock::getTitle() const
{
	return (this->_title);
}

void Warlock::setTitle(const std::string title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}
