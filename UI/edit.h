#ifndef EDIT_H
#define EDIT_H
#include <mainwindow.h>
#include <Models/peoplewithcomputers.h>
#include <string>
#include <QMessageBox>
#include "Processor/logic.h"
#include <Utilities/constants.h>
#include <QDate>

#include <QDialog>

namespace Ui {
class Edit;
}

/**
 * @brief very similar to editComputers.
 */

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = 0);
    void setSelectedPerson(peopleWithComputers MSelectedPerson);
    people getPersonChanged();
    void displayComputers(vector<computersWithPeople> computers);
    vector<int> getCheckedComputers();
    ~Edit();

private slots:
    void on_pushButtonSubmit_clicked();


    void on_ButtonCancel_clicked();

private:
    Ui::Edit *ui;
    peopleWithComputers selectedPerson;
    peopleWithComputers personToReturn;
    void displayPerson();
};

#endif // EDIT_H
