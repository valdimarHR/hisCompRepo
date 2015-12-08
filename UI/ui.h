#ifndef DISPLAY_H
#define DISPLAY_H

#include "Models/people.h"
#include "Processor/logic.h"
#include "Utilities/constants.h"
#include "DataFetch/datafetch.h"
#include <QtGlobal>

/**
 * @brief The UI prints out display, gets information from the use to
 * send to logic. Connects the user to the logic. Checks if the input
 * is correct.
 */

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
    /*
     * searchMenu asks the user whether it wants to search for a person or a computer and goes to
     * the appropriate function
     */
    void searchMenu();
    /*
     * searchMenuPerson asks the user in which way it wants to search for a person and gives the options of name,
     * gender, year of birth and year of death and returns the person the user is searching for
     */
    void searchMenuPerson();
    /*
     * searchMenuComputer asks the user in which way it wants to search for a computer and gives the options of name,
     * type, year of creation and whether or not it was built and returns the computer the person is searching for
     */
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
    int printOnlyPeople(const vector<peopleWithComputers>& peep);//Simple print to screen only the list of people.
    int printOnlyComputers(const vector<computersWithPeople>& comp);//Simple print to screen only list of computers.
    string getStringSearchValue(string question);
    bool inputStrToBool(string& built);
    void clear() const;
};

#endif // UI_H
