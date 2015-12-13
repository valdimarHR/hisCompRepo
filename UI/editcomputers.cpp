#include "editcomputers.h"
#include "ui_editcomputers.h"

editComputers::editComputers(const computersWithPeople& selectedComputer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputers)
{
    ui->setupUi(this);
    computerToEdit = selectedComputer;
    displayComputer();
}

editComputers::~editComputers()
{
    delete ui;
}

void editComputers::on_pushButtonSubmit_clicked()
{
    string name = ui->lineEditName->text().toStdString();
    string type = ui->lineEditType->text().toStdString();
    int yearCreated = ui->lineEditYearCreated->text().toUInt();
    bool wasCreated;
    string StrWasBuilt = ui->comboBoxBuilt->currentText().toStdString();
    if(StrWasBuilt == "Yes")
        wasCreated = true;
    else
        wasCreated = false;

    string info = ui->textEditInfo->toPlainText().toStdString();

    //bæta við að geti ekki verið tómir reitir

    if(yearCreated == 0) //því ef toUnt convertar texta í 0;
    {
        QMessageBox::warning(this, "Warning", "Don't put a text for year\nof birth or year of death!");
        ui->lineEditYearCreated->setText("");
        return;
    }

    int currentId = computerToEdit.c.getId();

    //senda allar upplýsingarnar einhvern veginn til DB.

    this->close();
}

void editComputers::displayComputer()
{
    ui->lineEditName->setText((QString::fromStdString(computerToEdit.c.getName())));
    ui->lineEditType->setText((QString::fromStdString(computerToEdit.c.getType())));
    ui->lineEditYearCreated->setText(QString::number(computerToEdit.c.getYearCreated()));
    if(computerToEdit.c.getWasBuilt() == true)
        ui->comboBoxBuilt->setCurrentIndex(0);
    else
        ui->comboBoxBuilt->setCurrentIndex(1);
    ui->textEditInfo->setText((QString::fromStdString(computerToEdit.c.getInfo())));
}

void editComputers::on_ButtonCancel_clicked()
{
    this->close();
}