#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/**
 * @brief computers includes all information about a computer, but not who made it.
 */

class computers
{
public:
    computers();
    computers(const string& n, const int& y, const string& t, const bool& b);
    computers(const int& i,const string& n, const int& y, const string& t, const bool& b);
    void setId (int fid);
    void setName(string fname);
    void setYearCreated(int year);
    void setType(string ftype);
    void setWasBuilt(bool built);
    int getId() const;
    string getName() const;
    int getYearCreated() const;
    string getType() const;
    bool getWasBuilt() const;
    /**
     * @brief Overwrites the comparison operator.
     * @returns a bool that is true if the computers have all information the same except id.
     */
    friend bool operator == (const computers& computer1, const computers& computer2);
private:
    int id;
    string name;
    int yearCreated;
    string type;
    bool wasBuilt;
};

#endif // COMPUTERS_H
