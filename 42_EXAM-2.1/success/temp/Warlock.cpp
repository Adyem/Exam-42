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
	std::map <std::string, ASpell *>::iterator it;

	it = _spellbook.begin();
	while (it != _spellbook.end())
	{
		delete it->second;
		it++;
	}
	_spellbook.clear();
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
	if (_spellbook.find(spell->getName()) == _spellbook.end())
		_spellbook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spellname)
{
	if (_spellbook.find(spellname) != _spellbook.end())
		_spellbook.erase(_spellbook.find(spellname));
}

void Warlock::launchSpell(std::string spellname, ATarget &target)
{
	if (_spellbook.find(spellname) != _spellbook.end())
		_spellbook[spellname]->launch(target);
}
