#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Dummy") {}

Dummy::~Dummy() {}

Dummy *Dummy::clone() const
{
	return (new Dummy());
}
