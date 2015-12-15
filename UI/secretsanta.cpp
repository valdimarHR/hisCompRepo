#include "secretsanta.h"
#include "ui_secretsanta.h"

secretSanta::secretSanta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secretSanta)
{
    ui->setupUi(this);
}

secretSanta::~secretSanta()
{
    delete ui;
}

void secretSanta::on_ButtonChristmas_clicked()
{
    this->close();
}
