#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) : 
	_name(name), _effects(effects) {}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return (*this);
}

ASpell::ASpell(const ASpell &other)
{
	*this = other;
}

const std::string &ASpell::getName() const
{
	return (this->_name);
}

const std::string &ASpell::getEffects() const
{
	return (this->_effects);
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
