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

computers::computers(const int& i,const string& n, const int& y, const string& t, const bool& b)
{
    id = i;
    name = n;
    yearCreated = y;
    type = t;
    wasBuilt = b;
}

void computers::setId(int fid)
{
    id = fid;
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

bool operator == (const computers& computer1, const computers& computer2)
{
    bool theSame = true;
    if (!(computer1.getName()== computer2.getName()))
        theSame = false;
    if (!(computer1.getYearCreated()== computer2.getYearCreated()))
        theSame = false;
    if (!(computer1.getType()== computer2.getType()))
        theSame = false;
    if (!(computer1.getWasBuilt()== computer2.getWasBuilt()))
        theSame = false;
    return theSame;
}

