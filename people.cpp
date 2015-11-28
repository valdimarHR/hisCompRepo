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

void people::setBirth(string fbirth)
{
    //Fyrst breyta í int
    //yearOfBirth = fbirth;
}

void people::setDeath(string fdeath)
{
    //Fyrst breyta í int
    //yearOfDeath = fdeath;
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

