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

void ClickComputer::setSelectedComputer(computersWithPeople MSelectedComputer)
{
    selectedComputer = MSelectedComputer;
    displayComputer();
}

void ClickComputer::displayComputer()
{
    ui->labelNameValue->setText(QString::fromStdString(selectedComputer.c.getName()));
    ui->labelCreatedValue->setText(QString::number(selectedComputer.c.getYearCreated()));
    if(selectedComputer.c.getWasBuilt())
    {
        ui->labelBuiltValue->setText("Yes");
    }
    else
    {
        ui->labelBuiltValue->setText("No");
    }
    ui->labelTypeValue->setText(QString::fromStdString(selectedComputer.c.getType()));
    ui->textEditInfo->insertPlainText(QString::fromStdString(selectedComputer.c.getInfo()));
    string personString = "";
    for(int i = 0; i < selectedComputer.creators.size(); i++)
    {
        personString += selectedComputer.creators[i].getName();
        personString += "\n";
    }
    ui->labelScientistValue->setText(QString::fromStdString(personString));
}

void ClickComputer::on_pushButton_clicked()
{
    this->close();
}
