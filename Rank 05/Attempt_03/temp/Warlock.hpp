#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock &operator=(const Warlock &other);
		Warlock(const Warlock &other);
		std::map <std::string, ASpell *> _spellbook;

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string name);
		void launchSpell(const std::string name, const ATarget &target);
};

#endif
