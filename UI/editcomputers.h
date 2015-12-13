#ifndef EDITCOMPUTERS_H
#define EDITCOMPUTERS_H

#include <QDialog>

namespace Ui {
class editComputers;
}

class editComputers : public QDialog
{
    Q_OBJECT

public:
    explicit editComputers(QWidget *parent = 0);
    ~editComputers();

private slots:
    void on_pushButtonSubmit_clicked();

private:
    Ui::editComputers *ui;
};

#endif // EDITCOMPUTERS_H
