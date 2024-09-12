#include "BrickWall.hpp"
#include "ATarget.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

BrickWall *BrickWall::clone() const
{
	return (new BrickWall);
}
