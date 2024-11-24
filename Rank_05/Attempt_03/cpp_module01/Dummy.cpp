#include "Dummy.hpp"
#include "ATarget.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

Dummy *Dummy::clone() const
{
	return (new Dummy);
}
