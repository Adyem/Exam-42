#include "Fwoosh.hpp"
#include "ASpell.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "Fwooshed") {}

Fwoosh::~Fwoosh() {}

Fwoosh *Fwoosh::clone() const
{
	return (new Fwoosh());
}
