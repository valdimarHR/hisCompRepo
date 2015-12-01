#ifndef PEOPLE_H
#define PEOPLE_H
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

//using namespace std;

const int notDead = -1;

class people
{
public:
    people();
    void setName(std::string fname);
    void setGender(std::string fgender);
    void setBirth(int fbirth);
    void setDeath(int fdeath);
    std::string getName() const;
    std::string getGender() const;
    int getBirth() const;
    int getDeath() const;
    void printPerson() const;
    friend bool operator == (const people &person1, const people &person2);
private:
    std::string name;
    std::string gender;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PEOPLE_H
