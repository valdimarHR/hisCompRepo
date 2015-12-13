#ifndef EDIT_H
#define EDIT_H
#include <mainwindow.h>
#include <Models/peoplewithcomputers.h>
#include <string>
#include <QMessageBox>
#include "Processor/logic.h"

#include <QDialog>

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(peopleWithComputers selectedPersonFromMain, QWidget *parent = 0);
    ~Edit();

private slots:
    void on_pushButtonSubmit_clicked();


    void on_ButtonCancel_clicked();

private:
    Ui::Edit *ui;
    peopleWithComputers selectedPerson;
    logic TheLogic;
    void displayPerson();
};

#endif // EDIT_H
