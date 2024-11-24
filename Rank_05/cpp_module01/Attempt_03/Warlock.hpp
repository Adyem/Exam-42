#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook _spellbook;
		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &name);
		void launchSpell(std::string const &name, ATarget const &target);
		void createSpell(std::string const &spellName);
};  

#endif
