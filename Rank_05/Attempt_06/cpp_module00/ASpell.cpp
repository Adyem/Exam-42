#include <string>
#include "ASpelll.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->effects = other._effects;
	}
	return (*this);
}

ASpell::ASpell(const ASpell &other)
{
	*this = other;
}

const std::string &ASpell::getName() const
{
	return (this->name);
}

const std::string &ASpell::getEffects() const
{
	return (this->effects)
}
