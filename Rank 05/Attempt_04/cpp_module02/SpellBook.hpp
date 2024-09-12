#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <map>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
	private:
		std::map <std::string, ASpell *> _spellbook;
		SpellBook &operator=(const SpellBook &other);
		SpellBook(const SpellBook &other);

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spellname);
		ASpell *createSpell(std::string const &spellname);
};

#endif
