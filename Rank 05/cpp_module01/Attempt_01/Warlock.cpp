#include "Warlock.hpp"
#include <iostream>
#include <map>
#include "ASpell.hpp"

Warlock::Warlock() {}

Warlock &Warlock::operator=(Warlock const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_title = other._title;
	}
	return (*this);
}

Warlock::Warlock(const Warlock &other)
{
	*this = other;
}

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return (this->_name);
}
const std::string &Warlock::getTitle() const
{
	return (this->_title);
}

void Warlock::setTitle(const std::string &title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (spellbook.find(spell->getName()) == spellbook.end())
			spellbook[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(const std::string spellname)
{
	auto it = spellbook.find(spellname);
	if (it != spellbook.end())
	{
		delete it->second;
		spellbook.erase(it);
	}
}

void Warlock::launchSpell(const std::string spellname, ATarget &target)
{
	auto it = spellbook.find(spellname);
	if (it != spellbook.end())
		it->second->launch(target);
}
