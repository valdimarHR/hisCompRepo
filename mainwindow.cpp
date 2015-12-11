#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllPeople()
{
    vector<peopleWithComputers> people = theLogic.printerSortPeople(1, 1);
    displayPeople(people);
}

void MainWindow::displayPeople(vector<peopleWithComputers> people)
{
    //ui->listPeople->clear();
    for(unsigned int i = 0; i < people.size(); i++)
    {
        peopleWithComputers currPerson = people[i];
        //ui->tablePeople->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currPerson.p.getName())));
    }
}

void MainWindow::on_buttonPeopleAdd_clicked()
{
    QString qName = ui ->lineEditPeopleName ->text();
    QString qGender = ui->dropDownPeopleGender->currentText();
    QString qBirth = ui->lineEditPeopleBirth->text();
    QString qDeath = ui->lineEditPeopleDeath->text();

    if (qName.isEmpty()||qGender=="*Select"||qBirth.isEmpty())
    {
        ui->labelPeopleError->setText("Everything with a * needs to be filled!");
        return;
    }

    string name = qName.toStdString();
    string gender = qGender.toStdString();
    int birth = qBirth.toUInt();
    int death;

    if (qDeath.isEmpty())
        death = constants::notDead;
    else
        death = qDeath.toUInt();

    if (death > birth)
    {
        ui->labelPeopleError->setText("Person can't die before they are born!");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    bool onList = theLogic.insertPerson(name, gender, birth, death);
    if(onList)
    {
        ui->labelPeopleError->setText("Person was already on the list.");
        ui->lineEditPeopleName->setText("");
        ui->dropDownPeopleGender->setCurrentIndex(0);
        ui->lineEditPeopleBirth->setText("");
        ui->lineEditPeopleDeath->setText("");
        return;
    }
    else
    {
        ui->lineEditPeopleFilter->setText("");
        displayAllPeople();
        ui->lineEditPeopleName->setText("");
        ui->dropDownPeopleGender->setCurrentIndex(0);
        ui->lineEditPeopleBirth->setText("");
        ui->lineEditPeopleDeath->setText("");
    }
}

void MainWindow::on_lineEditPeopleName_textEdited(const QString &arg1)
{
    ui->labelPeopleError->setText("");
}

void MainWindow::on_lineEditPeopleBirth_textEdited(const QString &arg1)
{
    ui->labelPeopleError->setText("");
}

void MainWindow::on_lineEditPeopleDeath_textEdited(const QString &arg1)
{
    ui->labelPeopleError->setText("");
}

void MainWindow::on_dropDownPeopleGender_activated(const QString &arg1)
{
    ui->labelPeopleError->setText("");
}
