#include "Warlock.hpp"
#include <string>
#include <iostream>
#include <map>

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	while (_spellbook.begin() != _spellbook.end())
	{
		delete _spellbook.begin()->second;
		_spellbook.erase(_spellbook.begin());
	}
}

const std::string &Warlock::getName() const
{
	return (this->_name);
}

const std::string &Warlock::getTitle() const
{
	return (this->_title);
}

void Warlock::setTitle(std::string const &title)
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
		_spellbook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string name)
{
	if (_spellbook.find(name) != _spellbook.end())
	{
		delete _spellbook.find(name)->second;
		_spellbook.erase(_spellbook.find(name));
	}
}

void Warlock::launchSpell(const std::string name, const ATarget &target)
{
	if (_spellbook.find(name) != _spellbook.end())
		_spellbook.find(name)->second->launch(target);
}
