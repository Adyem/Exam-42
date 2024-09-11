#ifndef WARLOKC_HPP
# define WARLOKC_HPP

#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::map <std::string, ASpell *> _spellbook;
		std::string _name;
		std::string _title;
		Warlock();
		Warlock &operator=(const Warlock &other);
		Warlock(const Warlock &other);

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellname);
		void launchSpell(std::string spellname, ATarget &target);
};

#endif