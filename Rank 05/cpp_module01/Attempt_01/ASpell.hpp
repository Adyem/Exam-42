#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>
#include <iostream>

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;

	public:
		virtual ASpell *clone() const = 0;
		const std::string &getName() const;
		const std::string &getEffects() const;
		ASpell(const std::string &name, const std::string &effects);
		virtual ~ASpell();
		ASpell &operator=(const ASpell &other);
		ASpell(const ASpell &other);
		void launch(const ATarget &target) const;
};

#endif
