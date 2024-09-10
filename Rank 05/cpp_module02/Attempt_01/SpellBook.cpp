#include "SpellBook.hpp"
#include <map>
#include <string>

SpellBook &SpellBook::operator=(const SpellBook &other)
{
	if (this != &other)
		_SpellBook = other._SpellBook;
	return (*this);
}

SpellBook::SpellBook(const SpellBook &other)
{
	*this = other;
}

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    std::map <std::string, ASpell *>::iterator it;

    for (it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
        delete it->second;
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		_SpellBook[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const &name)
{

	if (_SpellBook.find(name) != _SpellBook.end())
	{
		delete _SpellBook[name];
		_SpellBook.erase(name);
	}
}

ASpell *SpellBook::createSpell(std::string const &spellname)
{
	ASpell* tmp = NULL;

	if (_SpellBook.find(spellname) != _SpellBook.end())
		tmp = _SpellBook[spellname];
	return (tmp);
}
