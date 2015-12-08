#include "people.h"

people::people()
{
    name = "default";
    gender = "default";
    yearOfBirth = 0;
    yearOfDeath = 0;
}

people::people(const string& n, const string& g, const int& b, const int& d)
{
    name = n;
    gender = g;
    yearOfBirth = b;
    yearOfDeath = d;
}

people::people(const int& i,const string& n, const string& g, const int& b, const int& d)
{
    id = i;
    name = n;
    gender = g;
    yearOfBirth = b;
    yearOfDeath = d;
}

void people::setId(int fid)
{
    id = fid;
}

void people::setName(string fname)
{
    name = fname;
}

void people::setGender(string fgender)
{
    gender = fgender;
}

void people::setBirth(int fbirth)
{
    yearOfBirth = fbirth;
}

void people::setDeath(int fdeath)
{
    yearOfDeath = fdeath;
}

int people::getId() const
{
    return id;
}

string people::getName() const
{
    return name;
}

string people::getGender() const
{
    return gender;
}

int people::getBirth() const
{
    return yearOfBirth;
}

int people::getDeath() const
{
    return yearOfDeath;
}

bool operator == (const people& person1, const people& person2)
{
    string name1Lower = person1.getName();
    std::transform(name1Lower.begin(), name1Lower.end(), name1Lower.begin(), ::tolower);

    string name2Lower = person2.getName();
    std::transform(name2Lower.begin(), name2Lower.end(), name2Lower.begin(), ::tolower);

    bool theSame = true;
    if (!(name1Lower == name2Lower))
        theSame = false;
    if (!(person1.getGender()== person2.getGender()))
        theSame = false;
    if (!(person1.getBirth()== person2.getBirth()))
        theSame = false;
    if (!(person1.getDeath()== person2.getDeath()))
        theSame = false;
    return theSame;
}
