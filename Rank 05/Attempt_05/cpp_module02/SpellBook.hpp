#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell *> _spellbook;
		SpellBook &operator=(const SpellBook &other);
		SpellBook(const SpellBook &other);

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *);
		void forgetSpell(const std::string &spellname);
		ASpell *createSpell(const std::string &spellname);
};

#endif
