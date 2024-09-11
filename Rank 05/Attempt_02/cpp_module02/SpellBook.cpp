#include "SpellBook.hpp"
#include <map>
#include "ASpell.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it;

	it = _spellbook.begin();
	while (it != _spellbook.end())
	{
		delete it->second;
		_spellbook.erase(it);
		it++;
	}
}

void SpellBook::learnSpell(const ASpell *spell)
{
	if (spell)
	{
		_spellbook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const &spellname)
{
	std::map<std::string, ASpell *>::iterator it;

	it = _spellbook.find(spellname);
	if (it != _spellbook.end())
	{
		delete it->second;
		_spellbook.erase(it);
	}
}

ASpell *SpellBook::createSpell(std::string const &spellname)
{
	ASpell *tmp = NULL;

	if (_spellbook.find(spellname) != _spellbook.end())
		tmp = _spellbook[spellname];
	return (tmp);
};
