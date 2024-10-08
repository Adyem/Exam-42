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
	ASpell *tmp = NULL;

	if (_spellbook.find(spellname) != _spellbook.end())
		tmp = _spellbook[spellname];
	return (tmp);
};
