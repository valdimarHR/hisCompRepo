#include "people.h"

using namespace std;

people::people()
{
    name = "default";
    gender = "default";
    yearOfBirth = "default";
    yearOfDeath = "default";
}

void people::setName(string fname)
{
    name = fname;
}

void people::setGender(string fgender)
{
    gender = fgender;
}

void people::setBirth(string fbirth)
{
    yearOfBirth = fbirth;
}

void people::setDeath(string fdeath)
{
    yearOfDeath = fdeath;
}

string people::getName()
const
{
    return name;
}

string people::getGender()
const
{
    return gender;
}

string people::getBirth()
const
{
    return yearOfBirth;
}

string people::getDeath()
const
{
    return yearOfDeath;
}

