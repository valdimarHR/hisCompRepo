#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
#include <vector>

using namespace std;

const int notDead = -1;

class people
{
public:
    people();
    void setName(string fname);
    void setGender(string fgender);
    void setBirth(int fbirth);
    void setDeath(int fdeath);
    string getName();
    string getGender();
    int getBirth();
    int getDeath();
private:
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
    pair<int, string> list;
};

#endif // PEOPLE_H
