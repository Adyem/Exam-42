#include <string>
#include <iostream>
#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock & Warlock::operator=(const Warlock &other)
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
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
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
	std::cout << _name << ": i am " << _name << ": " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell  *spell)
{
	if (spell)
	{
		if (this->_spellbook.find(spell->getName()) == _spellbook.end())
			_spellbook[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(std::string SpellName)
{
	if (_spellbook.find(SpellName) != _spellbook.end())
		_spellbook.erase(_spellbook.find(SpellName));
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_spellbook.find(SpellName) != _spellbook.end())
		_spellbook[SpellName]->launch(target);
}
