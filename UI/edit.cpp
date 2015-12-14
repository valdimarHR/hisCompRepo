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
    if(selectedPerson.p.getDeath() == constants::notDead)
        ui->lineEditPeopleDeath->setText("");
    else
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

    if(name.length()==0 || ui->lineEditPeopleBirth->text().isEmpty())
    {
        ui->labelEditPeopleError->setText("<span style='color: #FF0000'>Everything needs to be filled before submition!</span>");
        return;
    }

    if(birth == 0) //því ef toUnt convertar texta í 0;
    {
        QMessageBox::warning(this, "Warning", "Don't put a text for year\nof birth!");
        ui->lineEditPeopleBirth->setText("");
        return;
    }

    if(death == 0) //því ef toUnt convertar texta í 0;
    {
        QMessageBox::warning(this, "Warning", "Don't put a text for year\nof death!");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    if(QDate::currentDate().year() < birth || QDate::currentDate().year() < death)
    {
        QMessageBox::warning(this, "Warning","Error!\nPlease don't put birth or death in the future!");
        ui->lineEditPeopleBirth->setText("");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    if (death < birth && death!= constants::notDead) //Error ef dánarár er á undan fæðingarári
    {
        ui->labelEditPeopleError->setText("<span style='color: #FF0000'>Person can't die before they are born!</span>");
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
