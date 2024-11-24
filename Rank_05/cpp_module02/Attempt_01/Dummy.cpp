#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

Dummy &Dummy::operator=(const Dummy &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Dummy::Dummy(const Dummy &other) : ATarget(other) {}

Dummy *Dummy::clone() const
{
	return (new Dummy());
}
