#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget
{
	public:
		Dummy();
		Dummy &operator=(const Dummy &other);
		Dummy (const Dummy &other);
		~Dummy();
		Dummy *clone() const override;
};

#endif
