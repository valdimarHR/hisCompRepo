﻿#include "edit.h"
#include "ui_edit.h"

Edit::Edit(const peopleWithComputers& selectedPersonFromMain, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    selectedPerson = selectedPersonFromMain;
    displayPerson();
}

Edit::~Edit()
{
    delete ui;
}

void Edit::displayPerson()
{
    ui->lineEditName->setText(QString::fromStdString(selectedPerson.p.getName()));
    if(selectedPerson.p.getGender() == "Female")
        ui->comboBoxGender->setCurrentIndex(0);
    else
        ui->comboBoxGender->setCurrentIndex(1);
    ui->lineEditBirth->setText(QString::number(selectedPerson.p.getBirth()));
    ui->lineEditDeath->setText(QString::number(selectedPerson.p.getDeath()));
    ui->textEditInfo->setText(QString::fromStdString(selectedPerson.p.getInfo()));
}

void Edit::on_pushButtonSubmit_clicked()
{
    string name = ui->lineEditName->text().toStdString();
    string gender = ui->comboBoxGender->currentText().toStdString();
    int birth = ui->lineEditBirth->text().toUInt();
    int death = ui->lineEditDeath->text().toUInt();
    string info = ui->textEditInfo->toPlainText().toStdString();

    //bæta við að geti ekki verið tómir reitir

    if(birth == 0 || death == 0) //því ef toUnt convertar texta í 0;
    {
        QMessageBox::warning(this, "Warning", "Don't put a text for year\nof birth or year of death!");
        ui->lineEditBirth->setText("");
        ui->lineEditDeath->setText("");
        return;
    }

    int currentId = selectedPerson.p.getId();

    //logic TheLogic;
    //TheLogic.editPerson(currentId, name, gender, birth, death, info);

    this->close();
}

void Edit::on_ButtonCancel_clicked()
{
    this->close();
}