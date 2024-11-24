#include "Fwoosh.hpp"
#include "ASpell.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

Fwoosh *Fwoosh::clone() const
{
	return (new Fwoosh());
}
