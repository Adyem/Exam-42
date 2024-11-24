#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook 
{
	private:
		std::map <std::string, ASpell *> _spellbook;
		SpellBook &operator=(const SpellBook &other);
		SpellBook(const SpellBook &other);

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(const ASpell *spell);
		void forgetSpell(std::string const &spellname);
		ASpell *createSpell(std::string const &spellname);
};

#endif
