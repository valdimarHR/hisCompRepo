#ifndef DISPLAY_H
#define DISPLAY_H

#include "Models/people.h"
#include "Processor/logic.h"
#include "Utilities/constants.h"
#include "DataFetch/datafetch.h"
#include <QtGlobal>


using namespace std;

class ui
{
public:
    ui();
    bool start();
    void printTree() const;
    void printPeopleVector(const vector<peopleWithComputers>& list) const;
    void printComputersVector(const vector<computersWithPeople>& list) const;
private:
    logic theLogic;
    int choice;
    void mainMenu();
    void menuSwitch();
    void insertMenu();
    void insertMenuPerson();
    void insertMenuComputer();
    void insertMenuConnection();
    void printVector(const vector<peopleWithComputers> &list) const;
    void printVector(const vector<computersWithPeople> &list) const;
    void searchMenu();
    void searchMenuPerson();
    void searchMenuComputer();
    void printerMenu();
    void printerMenuPeople();
    void printerMenuComputers();
    void deleteMenu();
    void inputIntCheck(bool inputFail, int& var);
    void inputIntCheck(bool inputFail, int& var, int low, int high);
    void deletePeople();
    void deleteComputer();
    string getStringSearchValue(string question);
    bool inputStrToBool(string& built);
    void clear() const;
};

#endif // UI_H
