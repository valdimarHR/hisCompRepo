#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>

using namespace std;

const int notDead = -1;

class people
{
public:
    people();
    void setName(string fname);
    void setGender(string fgender);
    void setBirth(string fbirth);
    void setDeath(string fdeath);
    string getName();
    string getGender();
    int getBirth();
    int getDeath();
private:
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PEOPLE_H
