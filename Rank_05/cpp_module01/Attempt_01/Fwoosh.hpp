#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		Fwoosh &operator=(const Fwoosh &other);
		Fwoosh (const Fwoosh &other);
		~Fwoosh();
		Fwoosh *clone() const override;
};

#endif
