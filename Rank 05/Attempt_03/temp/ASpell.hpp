#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;

	public:
		ASpell(const std::string &name, const std::string &effects);
		virtual ~ASpell();
		ASpell &operator=(const ASpell &spell);
		ASpell(const ASpell &spell);
		const std::string &getName() const;
		const std::string &getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &target) const;
};

#endif
