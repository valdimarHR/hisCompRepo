#ifndef DISPLAY_H
#define DISPLAY_H

#include "Models/people.h"
#include "Processor/logic.h"
#include "Utilities/constants.h"

using namespace std;

class ui
{
public:
    ui();
    bool start();
    void printTree() const;
    void printVector(const vector<people>& list) const;
private:
    logic theLogic;
    int choice;
    void mainMenu();
    void menuSwitch();
    void insertMenu();
    void insertMenuPerson();
    void insertMenuComputer();
    void searchMenu();
    void searchMenuPerson();
    void searchMenuComputer();
    void printerMenu();
    void printerMenuPeople();
    void printerMenuComputers();
    void printerMenuAll();
    void deleteMenu();
    void inputIntCheck(bool inputFail, int& var);
    void inputIntCheck(bool inputFail, int& var, int low, int high);
    string getStringSearchValue(string question);
    int getIntSearchValue();
    bool inputStrToBool(string& built);
};

#endif // UI_H
