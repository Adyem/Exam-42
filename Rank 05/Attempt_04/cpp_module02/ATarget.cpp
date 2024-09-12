#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <iostream>

ATarget::ATarget(const std::string &type) : _type(type) {}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

ATarget::ATarget(const ATarget &other)
{
	*this = other;
}

const std::string &ATarget::getType() const
{
	return (this->_type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
