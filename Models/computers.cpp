#include "computers.h"

Computers::Computers()
{
    name = "default";
    yearCreated = 0;
    type = "default";
    wasBuilt = false;
}

void Computers::setName(string fname)
{
    name = fname;
}

void Computers::setYearCreated(int year)
{
    yearCreated = year;
}
void Computers::setType(string ftype)
{
    type = ftype;
}

void Computers::setWasBuilt(bool built)
{
    wasBuilt = built;
}

string Computers::getName() const
{
    return name;
}
int Computers::getYearCreated() const
{
    return yearCreated;
}
string Computers::getType() const
{
    return type;
}
bool Computers::getWasBuilt() const
{
    return wasBuilt;
}
