#include "Warlock.hpp"
#include <string>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

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
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	_spellbook.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string spellname)
{
	_spellbook.forgetSpell(spellname);
}

void Warlock::launchSpell(const std::string spellname, const ATarget &target)
{
	if (_spellbook.createSpell(spellname))
		_spellbook.createSpell(spellname)->launch(target);
}
