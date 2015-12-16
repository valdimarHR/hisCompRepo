#ifndef EDITCOMPUTERS_H
#define EDITCOMPUTERS_H

#include <QDialog>
#include "Models/computerswithpeople.h"
#include <QMessageBox>
#include <mainwindow.h>
#include <Models/peoplewithcomputers.h>
#include <string>
#include <Utilities/constants.h>

#include <QDate>

namespace Ui {
class editComputers;
}

/**
 * @brief pop up window that makes it easier to edit a person.
 */

class editComputers : public QDialog
{
    Q_OBJECT

public:
    explicit editComputers(QWidget *parent = 0);
    /**
     * @brief takes in a computer with people and displays all the information
     * in the window to make it easier to edit.
     * @param currently selected computer so it can be displayed.
     */
    void setSelectedComputer(const computersWithPeople& MSelectedComputer);
    /**
     * @returns an object of the class computer so it can be put in logic.
     */
    computers getComputerChanged();
    /**
     * @brief puts the people in a list where they can be checked
     * and unchecked.
     * @param vector with people with computers, only people used
     * but the function to apply this vector was ready.
     */
    void displayPeople(vector<peopleWithComputers> people);
    /**
     * @brief returns all the id numbers of the people that
     * were checked when changes were submitted.
     */
    vector<int> getCheckedPeople();
    ~editComputers();

private slots:

    void on_pushButtonSubmit_clicked();

    void on_ButtonCancel_clicked();

private:
    Ui::editComputers *ui;
    computersWithPeople selectedComputer;
    computers computerToReturn;
    void displayComputer();
};

#endif // EDITCOMPUTERS_H
