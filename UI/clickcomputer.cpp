#include "clickcomputer.h"
#include "ui_clickcomputer.h"

ClickComputer::ClickComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClickComputer)
{
    ui->setupUi(this);
}

ClickComputer::~ClickComputer()
{
    delete ui;
}
