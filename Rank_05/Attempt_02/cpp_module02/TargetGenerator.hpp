#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <map>
#include "ATarget.hpp"
#include <string>

class TargetGenerator
{
	private:
		TargetGenerator &operator=(const TargetGenerator &targetgenerator);
		TargetGenerator(const TargetGenerator &targetgenerator);
		std::map <std::string, ATarget *> _target;

	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &type);
		ATarget *createTarget(std::string const &type);

};

#endif
