#ifndef PEOPLE_H
#define PEOPLE_H
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class people
{
public:
    people();
    void setName(string fname);
    void setGender(string fgender);
    void setBirth(int fbirth);
    void setDeath(int fdeath);
    string getName() const;
    string getGender() const;
    int getBirth() const;
    int getDeath() const;
    friend bool operator == (const people &person1, const people &person2);
private:
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PEOPLE_H
