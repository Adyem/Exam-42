#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <map>
#include "ATarget.hpp"
#include <string>

class TargetGenerator
{
	private:
		std::map <std::string, ATarget *> _target;
		TargetGenerator &operator=(const TargetGenerator &other);
		TargetGenerator(const TargetGenerator &ohter);
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &target);
		ATarget *createTarget(std::string const &target);
};

#endif
