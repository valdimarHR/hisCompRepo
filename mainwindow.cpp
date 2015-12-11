#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablePeople->hideColumn(0);
    ui->tableComputer->hideColumn(0);
    ui->tablePeople->setColumnWidth(1,250);
    ui->tableComputer->setColumnWidth(1,250);
    ui->tableComputer->setColumnWidth(2,150);
    displayAllPeople();
    displayAllComputers();
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

void MainWindow::displayAllComputers()
{
    vector<computersWithPeople> computers = theLogic.printerSortComputers(1, 1);
    displayComputers(computers);
}

void MainWindow::displayPeople(vector<peopleWithComputers> people)
{
    ui->tablePeople->clearContents();
    ui->tablePeople->setRowCount(people.size());
    for(unsigned int row = 0; row < people.size(); row++)
    {
        peopleWithComputers currPerson = people[row];
        ui->tablePeople->setItem(row,0,new QTableWidgetItem(QString::number(currPerson.p.getId())));
        ui->tablePeople->setItem(row,1,new QTableWidgetItem(QString::fromStdString(currPerson.p.getName())));
        ui->tablePeople->setItem(row,2,new QTableWidgetItem(QString::fromStdString(currPerson.p.getGender())));
        ui->tablePeople->setItem(row,3,new QTableWidgetItem(QString::number(currPerson.p.getBirth())));
        ui->tablePeople->setItem(row,4,new QTableWidgetItem(QString::number(currPerson.p.getDeath())));
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

void MainWindow::displayComputers(vector<computersWithPeople> computers)
{
    ui->tableComputer->clearContents();
    ui->tableComputer->setRowCount(computers.size());
    for(unsigned int row = 0; row < computers.size(); row++)
    {
        computersWithPeople currComputer = computers[row];
        ui->tableComputer->setItem(row,0,new QTableWidgetItem(QString::number(currComputer.c.getId())));
        ui->tableComputer->setItem(row,1,new QTableWidgetItem(QString::fromStdString(currComputer.c.getName())));
        ui->tableComputer->setItem(row,2,new QTableWidgetItem(QString::fromStdString(currComputer.c.getType())));
        ui->tableComputer->setItem(row,3,new QTableWidgetItem(QString::number(currComputer.c.getYearCreated())));
        ui->tableComputer->setItem(row,4,new QTableWidgetItem(QString::number(currComputer.c.getWasBuilt())));
    }
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0)
    {
        ui->tableComputer->clearContents();
        displayAllPeople();
    }
    else if(index == 1)
    {
        ui->tablePeople->clearContents();
        displayAllComputers();
    }
}

void MainWindow::on_tablePeople_clicked(const QModelIndex &index)
{
    ui->buttonPeopleDelete->setEnabled(true);
}

void MainWindow::on_buttonPeopleDelete_clicked()
{
    int selectedRow = ui->tablePeople->currentRow();
    int id = ui->tablePeople->item(selectedRow, 0)->text().toInt();
    qDebug() << endl << "id : " << id;

    theLogic.eraseChosenPeople(id);

    displayAllPeople();
    ui->buttonPeopleDelete->setEnabled(false);
}
