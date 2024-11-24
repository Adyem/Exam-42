#include <map>
#include <string>
#include "SpellBook.hpp"
#include "ASpell.hpp"

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
	if (spell && _spellbook.find(spell->getName()) == _spellbook.end())
		_spellbook[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string &spellname)
{
	if (_spellbook.find(spellname) != _spellbook.end())
	{
		delete _spellbook.find(spellname)->second;
		_spellbook.erase(_spellbook.find(spellname));
	}
}

ASpell *SpellBook::createSpell(const std::string &spellname)
{
	if (_spellbook.find(spellname) != _spellbook.end())
		return (_spellbook[spellname]);
	return (NULL);
}
