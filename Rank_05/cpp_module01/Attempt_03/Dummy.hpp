#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();
		Dummy &operator=(const Dummy &other);
		Dummy(const Dummy &other);
		Dummy *clone() const;
};

#endif
