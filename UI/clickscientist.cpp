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

void ClickScientist::setSelectedPerson(peopleWithComputers MSelectedPerson)
{
    selectedPerson = MSelectedPerson;
    displayPerson();
}

void ClickScientist::displayPerson()
{
    ui->labelNameValue->setText(QString::fromStdString(selectedPerson.p.getName()));
    ui->labelBirthValue->setText(QString::number(selectedPerson.p.getBirth()));
    if(selectedPerson.p.getDeath() != -1)
    {
        ui->labelDeathValue->setText(QString::number(selectedPerson.p.getDeath()));
    }
    ui->labelGenderValue->setText(QString::fromStdString(selectedPerson.p.getGender()));
    string computerString = "";
    for(int i = 0; i < selectedPerson.creations.size(); i++)
    {
        if(selectedPerson.creations[i].getName() == "default") break;
        computerString += selectedPerson.creations[i].getName();
        computerString += "\n";
    }
    ui->labelComputersValue->setText(QString::fromStdString(computerString));
    ui->textEditInfoValue->setText(QString::fromStdString(selectedPerson.p.getInfo()));
}

void ClickScientist::on_pushButton_clicked()
{
    this->close();
}
