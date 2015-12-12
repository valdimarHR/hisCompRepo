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
    ui->tabWidget->setCurrentIndex(0);
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
        ui->tablePeople->showRow(row);
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

    if(birth == 0 || death == 0) //If qBirth or qDeath is not a number, toUInt converts it to 0. So this is an error when text is applied where number is expected.
    {
        QMessageBox::warning(this, "Warning","Error!\nYou have to enter a number for\nyear of birth and year of death.");
        ui->lineEditPeopleBirth->setText("");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    if (death < birth && death!= constants::notDead) //Error ef dánarár er á undan fæðingarári
    {
        ui->labelPeopleError->setText("Person can't die before they are born!");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    bool onList = theLogic.insertPerson(name, gender, birth, death);
    if(onList)
    {
        ui->labelPeopleError->setText("Person was already on the list.");
        clearPeopleInsert();
        return;
    }
    else
    {
        ui->lineEditPeopleFilter->setText("");
        ui->tablePeople->setSortingEnabled(false);
        displayAllPeople();
        ui->tablePeople->setSortingEnabled(true);
        clearPeopleInsert();
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
//    ui->tableComputer->setSortingEnabled(false);
//    ui->tableComputer->setSortingEnabled(true);
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
        ui->tableComputer->showRow(row);
    }
}

void MainWindow::clearPeopleInsert()
{
    ui->lineEditPeopleName->setText("");
    ui->dropDownPeopleGender->setCurrentIndex(0);
    ui->lineEditPeopleBirth->setText("");
    ui->lineEditPeopleDeath->setText("");
}

void MainWindow::clearComputerInsert()
{
    ui->lineEditComputerName->setText("");
    ui->lineEditComputerType->setText("");
    ui->lineEditComputerCreated->setText("");
    ui->dropDownComputerBuilt->setCurrentIndex(0);
}

int MainWindow::getSelectedIdPeople()
{
    int selectedRow = ui->tablePeople->currentRow();
    int id = ui->tablePeople->item(selectedRow, 0)->text().toInt();
    return id;
}

int MainWindow::getSelectedIdComputer()
{
    int selectedRow = ui->tableComputer->currentRow();
    int id = ui->tableComputer->item(selectedRow, 0)->text().toInt();
    return id;
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

    int id = getSelectedIdPeople();

    theLogic.eraseChosenPeople(id);
    ui->tablePeople->setSortingEnabled(false);
    displayAllPeople();
    ui->buttonPeopleDelete->setEnabled(false);
    ui->tablePeople->setSortingEnabled(true);
}

void MainWindow::on_buttonComputerAdd_clicked()
{
    QString qName = ui ->lineEditComputerName ->text();
    QString qType = ui ->lineEditComputerType ->text();
    QString qYearCreated = ui->lineEditComputerCreated->text();
    QString qWasBuilt = ui->dropDownComputerBuilt->currentText();

    if (qName.isEmpty()||qType.isEmpty()||qYearCreated.isEmpty()||qWasBuilt=="*Built?")
    {
        ui->labelComputerError->setText("Everything with a * needs to be filled!");
        return;
    }

    string name = qName.toStdString();
    string type = qType.toStdString();
    int yearCreated = qYearCreated.toUInt();
    bool wasBuilt;

    if(yearCreated == 0) //If yearCreated is not a number, toUInt converts it to 0. So this is an error when text is applied where number is expected.
    {
        QMessageBox::warning(this, "Warning","Error!\nYou have to enter a number for\nYear created!");
        ui->lineEditComputerCreated->setText("");
        return;
    }

    if (qWasBuilt == "Yes")
        wasBuilt = true;
    else
        wasBuilt = false;

    bool onList = theLogic.insertComputer(name, yearCreated, type, wasBuilt);
    if(onList)
    {
        ui->labelComputerError->setText("Computer was already on the list.");
        clearComputerInsert();
        return;
    }
    else
    {
        ui->lineEditComputersFilter->setText("");
        ui->tableComputer->setSortingEnabled(false);
        displayAllComputers();
        ui->tableComputer->setSortingEnabled(true);
        clearComputerInsert();
    }
}

void MainWindow::on_lineEditComputerName_textEdited(const QString &arg1)
{
    ui->labelComputerError->setText("");
}

void MainWindow::on_lineEditComputerType_textEdited(const QString &arg1)
{
    ui->labelComputerError->setText("");
}

void MainWindow::on_lineEditComputerCreated_textEdited(const QString &arg1)
{
    ui->labelComputerError->setText("");
}

void MainWindow::on_dropDownComputerBuilt_activated(const QString &arg1)
{
    ui->labelComputerError->setText("");
}
void MainWindow::on_tableComputer_clicked(const QModelIndex &index)
{
    ui->buttonComputerDelete->setEnabled(true);
}

void MainWindow::on_buttonComputerDelete_clicked()
{
    int id = getSelectedIdComputer();
    theLogic.eraseChosenComputer(id);
    ui->tableComputer->setSortingEnabled(false);
    displayAllComputers();
    ui->buttonComputerDelete->setEnabled(false);
    ui->tableComputer->setSortingEnabled(true);
}

void MainWindow::on_lineEditPeopleFilter_textChanged(const QString &inputText)
{
    int rowCount = ui->tablePeople->rowCount();
    if(inputText == "")
    {
        displayAllPeople();
    }
    else
    {
        int columnNum = ui->dropDownPeopleFilter->currentIndex() + 1;
        for(int row = 0; row < rowCount; row++)
        {
            bool genderFind = columnNum == 2;
            QString columnText = ui->tablePeople->item(row,columnNum)->text();
            if(!genderFind && !columnText.contains(inputText, Qt::CaseInsensitive))
            {
                ui->tablePeople->hideRow(row);
            }
            else if(genderFind && !columnText.contains(inputText))
            {
                ui->tablePeople->hideRow(row);
            }
            else
            {
                ui->tablePeople->showRow(row);
            }
        }

    }
}

void MainWindow::on_lineEditComputersFilter_textChanged(const QString &inputText)
{
    int rowCount = ui->tableComputer->rowCount();
    if(inputText == "")
    {
        displayAllComputers();
    }
    else
    {
        int columnNum = ui->dropDownComputersFilter->currentIndex() + 1;
        for(int row = 0; row < rowCount; row++)
        {
            QString columnText = ui->tableComputer->item(row,columnNum)->text();
            if(!columnText.contains(inputText, Qt::CaseInsensitive))
            {
                ui->tableComputer->hideRow(row);
            }
            else
            {
                ui->tableComputer->showRow(row);
            }
        }

    }
}
