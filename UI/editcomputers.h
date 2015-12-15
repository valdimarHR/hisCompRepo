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

class editComputers : public QDialog
{
    Q_OBJECT

public:
    explicit editComputers(QWidget *parent = 0);
    void setSelectedComputer(const computersWithPeople& MSelectedComputer);
    computers getComputerChanged();
    void displayPeople(vector<peopleWithComputers> people);
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
