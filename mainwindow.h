#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Models/peoplewithcomputers.h"
#include "Processor/logic.h"
#include <QtDebug>
#include "Utilities/constants.h"
#include <QMessageBox>

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

    void on_buttonPeopleAdd_clicked();

    void on_tablePeople_clicked(const QModelIndex &index);

    void on_buttonPeopleDelete_clicked();

    void on_lineEditPeopleName_textEdited(const QString &arg1);

    void on_lineEditPeopleBirth_textEdited(const QString &arg1);

    void on_lineEditPeopleDeath_textEdited(const QString &arg1);

    void on_dropDownPeopleGender_activated(const QString &arg1);

    void on_tabWidget_tabBarClicked(int index);

    void on_buttonComputerAdd_clicked();

    void on_lineEditComputerName_textEdited(const QString &arg1);

    void on_lineEditComputerType_textEdited(const QString &arg1);

    void on_lineEditComputerCreated_textEdited(const QString &arg1);

    void on_dropDownComputerBuilt_activated(const QString &arg1);

    void on_tableComputer_clicked(const QModelIndex &index);

    void on_buttonComputerDelete_clicked();

    void on_lineEditPeopleFilter_textChanged(const QString &arg1);

private:
    void displayAllPeople();
    void displayAllComputers();
    void displayPeople(vector<peopleWithComputers>);
    void displayComputers(vector<computersWithPeople>);
    void clearPeopleInsert();
    void clearComputerInsert();
    Ui::MainWindow *ui;
    logic theLogic;

};

#endif // MAINWINDOW_H
