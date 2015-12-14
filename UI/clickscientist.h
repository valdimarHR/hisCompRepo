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
    ~ClickScientist();


private slots:
    //void on_ClickScientist_accepted();


private:
    Ui::ClickScientist *ui;
};

#endif // CLICKSCIENTIST_H
