#include "TargetGenerator.hpp"
#include <string>
#include <map>
#include "ATarget.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it;
    for (it = _targets.begin(); it != _targets.end(); ++it) {
        delete it->second;
    }
    _targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (target) {
        if (_targets.find(target->getType()) == _targets.end()) {
            _targets[target->getType()] = target->clone();
        }
    }
}

void TargetGenerator::forgetTargetType(std::string const &type) {
    if (_targets.find(type) != _targets.end()) {
        delete _targets[type];  // Free memory for the target object
        _targets.erase(type);   // Remove the target from the map
    }
}

ATarget* TargetGenerator::createTarget(std::string const &type) {
    if (_targets.find(type) != _targets.end()) {
        return _targets[type]->clone();  // Return a clone of the target
    }
    return NULL;  // Target type not found
}

