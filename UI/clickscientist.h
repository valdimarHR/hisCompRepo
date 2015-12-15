#ifndef CLICKSCIENTIST_H
#define CLICKSCIENTIST_H
#include <mainwindow.h>
#include <Models/peoplewithcomputers.h>
#include <string>
#include <QMessageBox>
#include "Processor/logic.h"
#include <QDialog>

namespace Ui {
class ClickScientist;
}

class ClickScientist : public QDialog
{
    Q_OBJECT

public:
    explicit ClickScientist(QWidget *parent = 0);
    void setSelectedPerson(peopleWithComputers MSelectedPerson);
    void displayPerson();
    ~ClickScientist();


private slots:
    //void on_ClickScientist_accepted();


    void on_pushButton_clicked();

private:
    Ui::ClickScientist *ui;
    peopleWithComputers selectedPerson;
};

#endif // CLICKSCIENTIST_H
