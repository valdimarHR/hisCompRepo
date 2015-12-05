#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <iostream>
using namespace std;

class computers
{
public:
    computers();
    void setName(string name);
    void setYearCreated(int year);
    void setType(string type);
    void setWasBuilt(bool built);
    int getId() const;
    string getName() const;
    int getYearCreated() const;
    string getType() const;
    bool getWasBuilt() const;
private:
    int id;
    string name;
    int yearCreated;
    string type;
    bool wasBuilt;
};

#endif // COMPUTERS_H
