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
    string getName() const;
    string getGender() const;
    string getBirth() const;
    string getDeath() const;
private:
    string name;
    string gender;
    string yearOfBirth;
    string yearOfDeath;
};

#endif // PEOPLE_H
