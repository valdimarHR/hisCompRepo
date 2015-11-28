#include "people.h"

using namespace std;

people::people()
{

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
{
    return name;
}

string people::getGender()
{
    return gender;
}

int people::getBirth()
{
    return yearOfBirth;
}

int people::getDeath()
{
    return yearOfDeath;
}

