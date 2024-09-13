#include <map>
#include <string>
#include "ATarget.hpp"
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
	if (target && _target.find(target->getType()) == _target.end())
		_target[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
	if (_target.find(target) != _target.end())
	{
		delete _target.find(target)->second;
		_target.erase(_target.find(target));
	}
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
	if (_target.find(target) != _target.end())
		return (_target.find(target)->second);
	return (NULL);
}
