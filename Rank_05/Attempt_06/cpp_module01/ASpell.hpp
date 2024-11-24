#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;

	protected:
		ASpell();
		virtual ~ASpell();
		ASpell &operator=(const ASpell &other);
		ASpell(const ASpell &other);
		const std::string &getName() const;
		const std::string &getEffects() const;
		virtual ASpell *clone() const = 0;
};

#endif
