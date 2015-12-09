#ifndef DISPLAY_H
#define DISPLAY_H

#include "Models/people.h"
#include "Processor/logic.h"
#include "Utilities/constants.h"
#include "DataFetch/datafetch.h"
#include <QtGlobal>

/**
 * @brief The UI prints out to the display and gets information from the user and
 * sends it to the logic layer. Connects the user to the logic. Checks if the input
 * is correct.
 */

using namespace std;

class ui
{
public:
    ui();
    bool start();

private:
    logic theLogic;
    int choice;
    void mainMenu();
    /**
     * @brief menuSwitch switches between different manues depending on the users input.
     */
    void menuSwitch();
    /**
     * @brief asks for what you wish to insert (Scientist,
     * computer, connection)
     */
    void insertMenu();
    /**
     * @brief asks for info on the person that is
     * to be added and sends it to the logic layer.
     */
    void insertMenuPerson();
    /**
     * @brief asks for info of the computer that is to
     * be added and sends it to the logic layer.
     */
    void insertMenuComputer();
    /**
     * @brief displays possible person and computer to connect,
     * makes user decide connection and sends to logic layer.
     */
    void insertMenuConnection();
    /**
     * @brief asks the user whether it wants to search for a person or a computer and goes to
     * the appropriate function
     */
    void searchMenu();
    /**
     * @brief asks the user in which way it wants to search for a person and gives the options of name,
     * gender, year of birth and year of death and prints the people matching the user's input to standard output
     */
    void searchMenuPerson();
    /**
     * @brief asks the user in which way it wants to search for a computer and gices the options of name,
     * type, year of creation and whether or not it was built and prints the computers matching the user's
     * input to standard output
     */
    void searchMenuComputer();
    /**
     * @brief printerMenu() is the main UI for printing the entire data in the database without any search requirements.
     * Print also offers sorting of the data as the user likes.
     */
    void printerMenu();
    /**
     * @brief printerMenuPeople() is the UI for printing all the people in the database.
     */
    void printerMenuPeople();
    /**
     * @brief printerMenuComputers() is the UI for printing all the computers in the database.
     */
    void printerMenuComputers();
    void printTree() const;
    /**
     * @brief printPeopleVector() prints out the people and their computers as a table to the display.
     * @param list is the vector that will be printed.
     */
    void printPeopleVector(const vector<peopleWithComputers>& list) const;
    /**
     * @brief printComputersVector() prints out the computers and the people that created them as a table to the display.
     * @param list is the vector that will be printed.
     */
    void printComputersVector(const vector<computersWithPeople>& list) const;

    /**
     * @brief Asks the user what attribute they want to delete(Scientist, computer or all).
     */
    void deleteMenu();
    /**
     * @brief inputIntCheck(bool, int&) checks if the input from the user was an integer. If not it will ask the user to
     * try again.
     * @param inputFail is a bool value for if the stream failed when inputing to type int var.
     * @param var is the current value from the user.
     */
    void inputIntCheck(bool inputFail, int& var);
    /**
     * @brief inputIntCheck(bool, int&, int, int) checks if the input from the user was an integer and within the right range.
     * If not it will ask the user to try again.
     * @param inputFail is a bool value for if the stream failed when inputing to type int var.
     * @param var is the current value from the user.
     * @param low is the low value of the range that int needs to be in.
     * @param high is the high value of the range that int needs to be in.
     */
    void inputIntCheck(bool inputFail, int& var, int low, int high);
    /**
      * @brief Asks the user what scientist they wish to remove and sends on to logic layer.
      */
    void deletePeople();
    /**
      * @brief Asks the user which computer they wish to remove and sends on to logic layer.
      */
    void deleteComputer();
    /**
      * @brief Asks the user if he is sure he wishes to delete the entire SQL DB and
      * sends on to the logic layer.
      */
    void deleteDB();
    /**
     * @brief printOnlyPeople prints out the people,
     * the computers they made are ignored in this print function.
     * @param list is a vector with people to be printed,
     */
    int printOnlyPeople(const vector<peopleWithComputers>& peep);
    /**
     * @brief printOnlyPeople prints out the computers,
     * the invertors are ignored in this print function.
     * @param list is a vector with computers to be printed,
     */
    int printOnlyComputers(const vector<computersWithPeople>& comp);
    /**
     * @brief getStringSearchValue
     * @param question
     * @return
     */
    string getStringSearchValue(string question);
    /**
     * @brief inputStrToBool turnes "yes" and "no" into bool values.
     * @param built is the current string input from user.
     * @return true if input was Y/y/Yes/yes but false if it was N/n/No/no.
     */
    bool inputStrToBool(string& built);
    /**
     * @brief clear() sents a clear command to the console dependant on the user OS.
     */
    void clear() const;
};

#endif // UI_H
