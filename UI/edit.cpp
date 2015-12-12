#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    displayPerson();
}

Edit::~Edit()
{
    delete ui;
}

Edit::displayPerson()
{
    peopleWithComputers selectedPerson;
    //selectedPerson = mainwindow.getSelectedPerson();
    //ui->lineEditName->setText(selectedPerson.p.getName());
    if(selectedPerson.p.getGender() == "Female")
        ui->comboBoxGender->setCurrentIndex(0);
    else
        ui->comboBoxGender->setCurrentIndex(1);
    //ui->lineEditBirth->setText(selectedPerson.p.getBirth());
    //ui->lineEditBirth->setText(selectedPerson.p.getDeath());
    //ui->textEditInfo->setText(selectedPerson.p.getInfo());
}

void Edit::on_pushButtonSubmit_clicked()
{
    string name = ui->lineEditName->text().toStdString();
    string gender = ui->comboBoxGender->currentText().toStdString();
    int birth = ui->lineEditBirth->text().toUInt();
    int death = ui->lineEditDeath->text().toUInt();

    //bæta við að geti ekki verið tómir reitir

    if(birth == 0 || death == 0) //því ef toUnt convertar texta í 0;
    {
        QMessageBox::warning(this, "Warning", "Don't put a text for year\nof birth or year of death!");
        ui->lineEditBirth->setText("");
        ui->lineEditDeath->setText("");
        return;
    }

    //int currentId = mainwindow.getSelectedId();
    //TheLogic.editPerson(currentId, name, gender, birth, death);

    //this -> done;
}
