#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Models/peoplewithcomputers.h"
#include "Processor/logic.h"
#include "Utilities/constants.h"
#include <QApplication>
#include <QMessageBox>
#include "UI/edit.h"
#include "UI/editcomputers.h"
#include <QDate>
#include "UI/clickcomputer.h"
#include "UI/clickscientist.h"
#include <QMenu>
#include "UI/secretsanta.h"
#include "UI/readme.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    /**
     * @brief When Add button is clicked all information about a person
     * that a user has added is sent to logic and then the fields are cleaned.
     */
    void on_buttonPeopleAdd_clicked();
    /**
     * @brief Slot when people table is clicked to activate buttons.
     */
    void on_tablePeople_clicked(const QModelIndex &index);
    /**
     * @brief Takes the id from currently selected person in table
     * and sends to logic to delete from db.
     */
    void on_buttonPeopleDelete_clicked();
    /**
     * @brief Slot when name field is edited to clear error label, same for next four.
     */
    void on_lineEditPeopleName_textEdited(const QString &arg1);

    void on_lineEditPeopleBirth_textEdited(const QString &arg1);

    void on_lineEditPeopleDeath_textEdited(const QString &arg1);

    void on_dropDownPeopleGender_activated(const QString &arg1);

    /**
     * @brief When user changes tab, goes between people and computers,
     * the whole list is displayed again, filter field cleared.
     */
    void on_tabWidget_tabBarClicked(int index);
    /**
     * @brief information about a computer from user is sent to logic,
     * fields cleared.
     */
    void on_buttonComputerAdd_clicked();
    /**
     * @brief next four functions are used to clear error message in label.
     */
    void on_lineEditComputerName_textEdited(const QString &arg1);

    void on_lineEditComputerType_textEdited(const QString &arg1);

    void on_lineEditComputerCreated_textEdited(const QString &arg1);

    void on_dropDownComputerBuilt_activated(const QString &arg1);
    /**
     * @brief Makes buttons enabled when item in list is selected.
     */
    void on_tableComputer_clicked(const QModelIndex &index);
    /**
     * @brief When Delete is clicked the id from currently selected
     * computer in table is sent to logic to be deleted. Then the list
     * is displayed again.
     */
    void on_buttonComputerDelete_clicked();
    /**
     * @brief When text is changed in filter field, the list is displayed again,
     * live search. Same for next function.
     */
    void on_lineEditPeopleFilter_textChanged(const QString &arg1);

    void on_lineEditComputersFilter_textChanged(const QString &arg1);
    /**
     * @brief When edit button is clicked then editSelectedPerson is called.
     */
    void on_ButtonPeopleEdit_clicked();
    /**
     * @brief When edit button is clicked then editSelectedComputer is called.
     */
    void on_ButtonComputersEdit_clicked();
    /**
     * @brief When a computer is double clicked then a new window opens with info of that computer.
     */
    void on_tableComputer_doubleClicked(const QModelIndex &index);
    /**
     * @brief When a scientist is double clicked then a new window opens with info of that scientist.
     */
    void on_tablePeople_doubleClicked(const QModelIndex &index);
    /**
     * @brief the action slot when table is right clicked
     */
    void on_tablePeople_customContextMenuRequested(const QPoint & pos);
    /**
     * @brief open editSelected when Edit is clicked after right clicking.+
     * Nex two are the same except for computer table.
     */
    void on_actionRightClicked_triggered();

    void on_tableComputer_customContextMenuRequested(const QPoint &pos);

    void on_actionComputerRightClicked_triggered();
    /**
     * @brief
     */
    void editSelectedPerson();

    void editSelectedComputer();

    void on_actionOpen_readme_file_triggered();

    void on_tableComputer_entered(const QModelIndex &index);

    void on_tablePeople_entered(const QModelIndex &index);

private:
    /**
     * @brief displayAllPeople prepares a list of all the people so it can be printed with displaypeople.
     */
    void displayAllPeople();
    /**
     * @brief displayAllComputers prepares a list of all computers so it can be printed with displayComputers.
     */
    void displayAllComputers();
    /**
     * @brief displayPeople, displays the peopleWithComputers vector to the table in the program.
     */
    void displayPeople(vector<peopleWithComputers>);
    /**
     * @brief displayComputers, displays the computersWithPeople vector to the table in the program.
     */
    void displayComputers(vector<computersWithPeople>);
    /**
     * @brief clearPeopleInsert clears the fields where users write info of a person to be added.
     */
    void clearPeopleInsert();
    /**
     * @brief clearComputerInsert clears the fields where users write info of a computer.
     */
    void clearComputerInsert();
    /**
     * @brief getSelectedIdPeople checks where user has selected on the table and gets the id of that scientist.
     * @return the id of the selected scientist.
     */
    int getSelectedIdPeople();
    /**
     * @brief getSelectedIdComputer checks where user has selected on the table and gets the id of that computer.
     * @return the id of the selected computer.
     */
    int getSelectedIdComputer();
    /**
     * @brief getSelectedPerson calls getSelectedIdPeople and then fetches from the db all info of that scientist.
     * @return all the info of the selected person.
     */
    peopleWithComputers getSelectedPerson();
    /**
     * @brief getSelectedComputer calls getSelectedIdComputer() and then fetches from the db all info of that computer.
     * @return all the info of the selected computer.
     */
    computersWithPeople getSelectedComputer();
    Ui::MainWindow *ui;
    logic theLogic;

};

#endif // MAINWINDOW_H
