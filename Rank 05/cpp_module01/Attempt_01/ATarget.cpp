#include "ATarget.hpp"
#include "ASpell.hpp"
#include <iostream>

const std::string &ATarget::getType() const
{
	return (this->_type);
}

ATarget::ATarget(const std::string &type) : _type(type) {}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

ATarget::ATarget(const ATarget &other)
{
	*this = other;
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->_type << " has been " << spell.getEffects() << std::endl;
}
