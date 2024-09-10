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
	_spellbook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string const &spellName)
{
	_spellbook.forgetSpell(spellName);
}

void Warlock::createSpell(std::string const &spellName)
{
	_spellbook.createSpell(spellName);
}

void Warlock::launchSpell(std::string const &spellName, ATarget const & target)
{
	if (_spellbook.createSpell(spellName))
		_spellbook.createSpell(spellName)->launch(target);
}
