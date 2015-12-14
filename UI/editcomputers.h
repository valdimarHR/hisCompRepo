#ifndef EDITCOMPUTERS_H
#define EDITCOMPUTERS_H

#include <QDialog>
#include "Models/computerswithpeople.h"
#include <QMessageBox>

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
