#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <map>
#include <string>

class ASpell;
class ATarget;

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock &operator=(const Warlock &other);
		Warlock (const Warlock &other);
		std::map < std::string, ASpell * > spellbook;

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string spellname);
		void launchSpell(const std::string spellname, ATarget &target);
};

#endif
