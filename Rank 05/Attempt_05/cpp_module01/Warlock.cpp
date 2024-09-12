#include <string>
#include "Warlock.hpp"
#include <iostream>
#include <map>

Warlock::Warlock(const std::string &name, const std::string &title) :
	_name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	while (_spellbook.begin() != _spellbook.end())
	{
		delete _spellbook.begin()->second;
		_spellbook.erase(_spellbook.begin());
	}
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
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		_spellbook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string spellname)
{
	if (_spellbook.find(spellname) != _spellbook.end())
	{
		delete _spellbook.find(spellname)->second;
		_spellbook.erase(_spellbook.find(spellname));
	}
}

void Warlock::launchSpell(const std::string spellname, const ATarget &target)
{
	if (_spellbook.find(spellname) != _spellbook.end())
		_spellbook.find(spellname)->second->launch(target);
}
