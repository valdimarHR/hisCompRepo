#include "people.h"

using namespace std;

people::people()
{
    name = "default";
    gender = "default";
    yearOfBirth = 0;
    yearOfDeath = 0;
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

int people::getBirth()
const
{
    return yearOfBirth;
}

int people::getDeath()
const
{
    return yearOfDeath;
}

void people::printPerson() const
{
    cout << "Name: " << name
         << " |Gender: " << gender
         << " |Year of Birth: " << yearOfBirth
         << " |Year of Death: " << yearOfDeath << endl;
}

