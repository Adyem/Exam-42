#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string>

class ASpell;

class ATarget
{
	protected:
		std::string _type;

	public:
		const std::string getType() const;
		ATarget(const std::string &type);
		virtual ~ATarget();
		ATarget &operator=(const ATarget &other);
		ATarget(const ATarget &other);
		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &spell) const;
};

#endif
