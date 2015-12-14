#ifndef CLICKCOMPUTER_H
#define CLICKCOMPUTER_H
#include <mainwindow.h>
#include "Models/computerswithpeople.h"
#include "Processor/logic.h"
#include <QMessageBox
#include <QDialog>

namespace Ui {
class ClickComputer;
}

class ClickComputer : public QDialog
{
    Q_OBJECT

public:
    explicit ClickComputer(const computersWithPeople& selectedComputer, QWidget *parent = 0);
    ~ClickComputer();

private slots:
    void on_ClickComputer_accepted();

private:
    Ui::ClickComputer *ui;
    peopleWithComputers selectedPerson;
    void displayPerson();
};

#endif // CLICKCOMPUTER_H
