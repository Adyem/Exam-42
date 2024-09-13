#include <map>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	while (_spellbook.begin() != _spellbook.end())
	{
		delete _spellbook.begin()->second;
		_spellbook.erase(_spellbook.begin());
	}
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell && _spellbook.find(spell->getName()) != _spellbook.end())
		_spellbook[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const &spellname)
{
	if (_spellbook.find(spellname) != _spellbook.end())
	{
		delete _spellbook.find(spellname)->second;
		_spellbook.erase(_spellbook.find(spellname));
	}
}

ASpell *SpellBook::createSpell(std::string const &spellname)
{
	if (_spellbook.find(spellname) != _spellbook.end())
		return (_spellbook.find(spellname)->second);
	return (NULL);
}
