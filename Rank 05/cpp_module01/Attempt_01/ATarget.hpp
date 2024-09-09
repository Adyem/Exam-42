#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string>

class ASpell;

class ATarget
{
	protected:
		std::string _type;

	public:
		virtual ATarget *clone() const = 0;
		const std::string &getType() const;
		ATarget(const std::string &type);
		virtual ~ATarget();
		ATarget &operator=(const ATarget &other);
		ATarget (const ATarget &other);
		void getHitBySpell(const ASpell &spell) const;
};

#endif
