#ifndef PEOPLE_H
#define PEOPLE_H
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <Utilities/constants.h>

using namespace std;

class people
{
public:
    people();
    people(const string& n, const string& g, const int& b, const int& d);
    people(const int& i,const string& n, const string& g, const int& b, const int& d);
    void setId(int fid);
    void setName(string fname);
    void setGender(string fgender);
    void setBirth(int fbirth);
    void setDeath(int fdeath);
    int getId() const;
    string getName() const;
    string getGender() const;
    int getBirth() const;
    int getDeath() const;
    friend bool operator == (const people &person1, const people &person2);
private:
    int id;
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PEOPLE_H
