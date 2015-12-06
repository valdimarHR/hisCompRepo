#include "computers.h"

computers::computers()
{
    name = "default";
    yearCreated = 0;
    type = "default";
    wasBuilt = false;
}

computers::computers(const string& n, const int& y, const string& t, const bool& b)
{
    name = n;
    yearCreated = y;
    type = t;
    wasBuilt = b;
}

void computers::setName(string fname)
{
    name = fname;
}

void computers::setYearCreated(int year)
{
    yearCreated = year;
}
void computers::setType(string ftype)
{
    type = ftype;
}

void computers::setWasBuilt(bool built)
{
    wasBuilt = built;
}

 int computers::getId() const
 {
     return id;
 }

string computers::getName() const
{
    return name;
}
int computers::getYearCreated() const
{
    return yearCreated;
}
string computers::getType() const
{
    return type;
}
bool computers::getWasBuilt() const
{
    return wasBuilt;
}
