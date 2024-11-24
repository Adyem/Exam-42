#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <map>
#include <string>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const &other);
		TargetGenerator &operator=(TargetGenerator const &other);

		std::map <std::string, ATarget *> _targets;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &type);
		ATarget *createTarget(std::string const &type);
};

#endif
