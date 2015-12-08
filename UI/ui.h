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
    void insertMenu();//Asks for what you wish to insert(Scientist, computer, connection).
    void insertMenuPerson();//Asks for info of the person that is to be added.
    void insertMenuComputer();//Asks for info of the computer that is to be added.
    void insertMenuConnection();
    void searchMenu(); //Asks the user whether it wants to search for a person or a computer and goes to the appropriate function
    void searchMenuPerson();
    void searchMenuComputer();
    void printerMenu();
    void printerMenuPeople();
    void printerMenuComputers();
    void deleteMenu();//Asks the user what attribute they want to delete(Scientist, computer or all).
    void inputIntCheck(bool inputFail, int& var);
    void inputIntCheck(bool inputFail, int& var, int low, int high);
    void deletePeople();//Asks the user what scientist they wish to remove.
    void deleteComputer();//Asks the user what computer they wish to remove.
    void deleteDB();//Asks the user if he is sure he wish to delete the entire SQL DB.
    int printOnlyPeople(const vector<people>& peep);//Simple print to screen only the list of people.
    int printOnlyComputers(const vector<computers>& comp);//Simple print to screen only list of computers.
    string getStringSearchValue(string question);
    bool inputStrToBool(string& built);
    void clear() const;
};

#endif // UI_H
