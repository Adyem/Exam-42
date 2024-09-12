#ifndef TARGETGENERRATOR_HPP
# define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <map>
#include <string>

class TargetGenerator
{
	private:
		std::map <std::string, ATarget *> _target;
		TargetGenerator &operator=(const TargetGenerator &other);
		TargetGenerator(const TargetGenerator &other);

	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &targettype);
		ATarget *createTarget(std::string const &targettype);
};

#endif
