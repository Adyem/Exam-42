#include "Fwoosh.hpp"
#include "ASpell.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "Fwooshed") {}

Fwoosh::~Fwoosh() {}

Fwoosh &Fwoosh::operator=(const Fwoosh &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return (*this);
}

Fwoosh::Fwoosh(const Fwoosh &other) : ASpell(other) {}

Fwoosh *Fwoosh::clone() const
{
	return (new Fwoosh());
}
