#include "Fireball.hpp"
#include "ASpell.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball() {}

Fireball *Fireball::clone() const
{
	return (new Fireball);
}
