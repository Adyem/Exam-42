#include "Warlock.hpp"
#include <string>
#include <iostream>
#include "ASpell.hpp"

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
	if (!spell)
		return ;
	if (_spellbook.find(spell->getName()) == _spellbook.end())
		_spellbook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string spellname)
{
	if (_spellbook.find(spellname) != _spellbook.end())
		_spellbook.erase(_spellbook.find(spellname));
}

void Warlock::launchSpell(const std::string spellname, const ATarget &target)
{
	if (_spellbook.find(spellname) != _spellbook.end())
		_spellbook[spellname]->launch(target);
}
