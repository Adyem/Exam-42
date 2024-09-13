#include "ATarget.hpp"
#include <map>
#include <string>
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	while (_target.begin() != _target.end())
	{
		delete _target.begin()->second;
		_target.erase(_target.begin());
	}
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target && _target.find(target->getType()) != _target.end())
		_target[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const &targettype)
{
	if (_target.find(targettype) != _target.end())
	{
		delete _target.find(targettype)->second;
		_target.erase(_target.find(targettype));
	}
}

ATarget *TargetGenerator::createTarget(std::string const &targettype)
{
	if (_target.find(targettype) != _target.end())
		return (_target.find(targettype)->second);
	return (NULL);
}
