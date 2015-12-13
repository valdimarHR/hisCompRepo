#include "editcomputers.h"
#include "ui_editcomputers.h"

editComputers::editComputers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputers)
{
    ui->setupUi(this);
}

editComputers::~editComputers()
{
    delete ui;
}

void editComputers::on_pushButtonSubmit_clicked()
{
    this->done(1);
}
