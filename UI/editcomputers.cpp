#include "editcomputers.h"
#include "ui_editcomputers.h"

editComputers::editComputers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputers)
{
    ui->setupUi(this);
}

void editComputers::setSelectedComputer(const computersWithPeople &MSelectedComputer)
{
    selectedComputer = MSelectedComputer;
    displayComputer();
}

computers editComputers::getComputerChanged()
{
    return computerToReturn;
}

editComputers::~editComputers()
{
    delete ui;
}

void editComputers::on_pushButtonSubmit_clicked()
{
    string name = ui->lineEditComputerName->text().toStdString();
    string type = ui->lineEditComputerType->text().toStdString();
    int yearCreated = ui->lineEditComputerYearCreated->text().toUInt();
    bool wasCreated;
    string StrWasBuilt = ui->comboBoxBuilt->currentText().toStdString();
    if(StrWasBuilt == "Yes")
        wasCreated = true;
    else
        wasCreated = false;

    string info = ui->textComputerEditInfo->toPlainText().toStdString();

    if (name.length() == 0 || type.length() == 0 || ui->lineEditComputerYearCreated->text().isEmpty())
    {
        //error í label, verður að vera útfyllt
        return;
    }

    if(yearCreated == 0) //því ef toUnt convertar texta í 0;
    {
        QMessageBox::warning(this, "Warning", "Don't put a text for year created!");
        ui->lineEditComputerYearCreated->setText("");
        return;
    }

    computerToReturn.setId(selectedComputer.c.getId());
    computerToReturn.setName(name);
    computerToReturn.setType(type);
    computerToReturn.setYearCreated(yearCreated);
    computerToReturn.setWasBuilt(wasCreated);
    computerToReturn.setInfo(info);

    this->done(1);
}

void editComputers::displayComputer()
{
    ui->lineEditComputerName->setText((QString::fromStdString(selectedComputer.c.getName())));
    ui->lineEditComputerType->setText((QString::fromStdString(selectedComputer.c.getType())));
    ui->lineEditComputerYearCreated->setText(QString::number(selectedComputer.c.getYearCreated()));
    if(selectedComputer.c.getWasBuilt() == true)
        ui->comboBoxBuilt->setCurrentIndex(0);
    else
        ui->comboBoxBuilt->setCurrentIndex(1);
    ui->textComputerEditInfo->setText((QString::fromStdString(selectedComputer.c.getInfo())));
}

void editComputers::on_ButtonCancel_clicked()
{
    this->done(0);
}
