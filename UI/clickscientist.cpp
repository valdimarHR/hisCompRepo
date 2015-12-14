#include "clickscientist.h"
#include "ui_clickscientist.h"

ClickScientist::ClickScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClickScientist)
{
    ui->setupUi(this);
}

ClickScientist::~ClickScientist()
{
    delete ui;
}

void ClickScientist::displaySci()
{

}
