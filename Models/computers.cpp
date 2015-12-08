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
    string name1Lower = computer1.getName();
    std::transform(name1Lower.begin(), name1Lower.end(), name1Lower.begin(), ::tolower);

    string name2Lower = computer2.getName();
    std::transform(name2Lower.begin(), name2Lower.end(), name2Lower.begin(), ::tolower);

    string type1Lower = computer1.getType();
    std::transform(type1Lower.begin(), type1Lower.end(), type1Lower.begin(), ::tolower);

    string type2Lower = computer2.getType();
    std::transform(type2Lower.begin(), type2Lower.end(), type2Lower.begin(), ::tolower);

    bool theSame = true;
    if (!(name1Lower == name2Lower))
        theSame = false;
    if (!(computer1.getYearCreated()== computer2.getYearCreated()))
        theSame = false;
    if (!(type1Lower == type2Lower))
        theSame = false;
    if (!(computer1.getWasBuilt()== computer2.getWasBuilt()))
        theSame = false;
    return theSame;
}

