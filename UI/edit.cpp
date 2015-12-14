#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
}

void Edit::setSelectedPerson(peopleWithComputers MSelectedPerson)
{
    selectedPerson = MSelectedPerson;
    displayPerson();
}

people Edit::getPersonChanged()
{
    return personToReturn.p;
}

Edit::~Edit()
{
    delete ui;
}

void Edit::displayPerson()
{
    ui->lineEditPeopleName->setText(QString::fromStdString(selectedPerson.p.getName()));
    if(selectedPerson.p.getGender() == "Female")
        ui->comboBoxGender->setCurrentIndex(0);
    else
        ui->comboBoxGender->setCurrentIndex(1);
    ui->lineEditPeopleBirth->setText(QString::number(selectedPerson.p.getBirth()));
    ui->lineEditPeopleDeath->setText(QString::number(selectedPerson.p.getDeath()));
    ui->textEditPeopleInfo->setText(QString::fromStdString(selectedPerson.p.getInfo()));
}

void Edit::on_pushButtonSubmit_clicked()
{
    string name = ui->lineEditPeopleName->text().toStdString();
    string gender = ui->comboBoxGender->currentText().toStdString();
    int birth = ui->lineEditPeopleBirth->text().toUInt();
    int death;
    if(ui->lineEditPeopleDeath->text() == "")
        death = constants::notDead;
    else
        death = ui->lineEditPeopleDeath->text().toUInt();
    string info = ui->textEditPeopleInfo->toPlainText().toStdString();

    //bæta við að geti ekki verið tómir reitir, framtíðartékki
    if(birth == 0 || death == 0) //því ef toUnt convertar texta í 0;
    {
        QMessageBox::warning(this, "Warning", "Don't put a text for year\nof birth or year of death!");
        ui->lineEditPeopleBirth->setText("");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    personToReturn.p.setId(selectedPerson.p.getId());
    personToReturn.p.setName(name);
    personToReturn.p.setGender(gender);
    personToReturn.p.setBirth(birth);
    personToReturn.p.setDeath(death);
    personToReturn.p.setInfo(info);

    this->done(1);
}

void Edit::on_ButtonCancel_clicked()
{
    this->done(0);
}
