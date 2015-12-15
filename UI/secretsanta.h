#ifndef SECRETSANTA_H
#define SECRETSANTA_H
#include <QMovie>

#include <QDialog>

namespace Ui {
class secretSanta;
}

class secretSanta : public QDialog
{
    Q_OBJECT

public:
    explicit secretSanta(QWidget *parent = 0);
    ~secretSanta();

private slots:
    void on_ButtonChristmas_clicked();

private:
    Ui::secretSanta *ui;
};

#endif // SECRETSANTA_H
