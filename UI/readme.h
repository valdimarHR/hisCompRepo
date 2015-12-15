#ifndef README_H
#define README_H

#include <QDialog>
#include <QTextStream>
#include <QFile>

namespace Ui {
class readMe;
}

class readMe : public QDialog
{
    Q_OBJECT

public:
    explicit readMe(QWidget *parent = 0);
    ~readMe();

private slots:
    void on_ButtonClose_clicked();

private:
    Ui::readMe *ui;
};

#endif // README_H
