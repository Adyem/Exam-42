#include "Warlock.hpp"
#include <string>
#include <iostream>

Warlock::Warlock() {};

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job is done!" << std::endl;
}

Warlock &Warlock::operator=(Warlock &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_title = other._title;
    }
    return *this;
}

Warlock::Warlock(Warlock &obj)
{
    *this = obj;
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day" << std::endl;
}

void Warlock::Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

std::string const &Warlock::getName() const
{
	return (this->_name);
}

std::string const &Warlock::getTitle() const
{
	return (this->_title);
}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}
