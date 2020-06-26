#include <iostream>
#include "GunObject.hpp"

class Virus : public GunObject
{
public:
    virtual std::string type() { return "Virus"; }

protected:
    int MSM_health;
    Virus() : GunObject() {}
    virtual ~Virus() {}
};