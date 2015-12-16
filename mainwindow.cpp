#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UI/clickscientist.h"
#include "UI/clickcomputer.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //First column is id and is not to be displayed, only for us to use.
    ui->tablePeople->hideColumn(0);
    ui->tableComputer->hideColumn(0);
    ui->tablePeople->setColumnWidth(1,250);
    ui->tableComputer->setColumnWidth(1,250);
    ui->tableComputer->setColumnWidth(2,150);
    ui->tablePeople->setMouseTracking(true);
    ui->tableComputer->setMouseTracking(true);
    displayAllPeople();
    displayAllComputers();
    //Make program always open with people selected.
    ui->tabWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllPeople()
{
    //The allPeopleSorted function takes in a orderby number and ascending number.
    //1 and 1 means sort by person name and ascending.
    vector<peopleWithComputers> people = theLogic.allPeopleSorted(1, 1);
    displayPeople(people);
}

void MainWindow::displayAllComputers()
{
    //The allComputersSorted function takes in a orderby number and ascending number.
    //1 and 1 means sort by computer name and ascending.
    vector<computersWithPeople> computers = theLogic.allComputersSorted(1, 1);
    displayComputers(computers);
}

void MainWindow::displayPeople(vector<peopleWithComputers> people)
{
    ui->tablePeople->setSortingEnabled(false);
    ui->tablePeople->clearContents();
    ui->tablePeople->setRowCount(people.size());
    for(unsigned int row = 0; row < people.size(); row++)
    {
        peopleWithComputers currPerson = people[row];
        ui->tablePeople->setItem(row,0,new QTableWidgetItem(QString::number(currPerson.p.getId())));
        ui->tablePeople->setItem(row,1,new QTableWidgetItem(QString::fromStdString(currPerson.p.getName())));
        ui->tablePeople->setItem(row,2,new QTableWidgetItem(QString::fromStdString(currPerson.p.getGender())));
        ui->tablePeople->setItem(row,3,new QTableWidgetItem(QString::number(currPerson.p.getBirth())));
        if(currPerson.p.getDeath() > 0)
        {
            ui->tablePeople->setItem(row,4,new QTableWidgetItem(QString::number(currPerson.p.getDeath())));
        }
        ui->tablePeople->showRow(row);
    }
    ui->tablePeople->setSortingEnabled(true);
}

void MainWindow::on_buttonPeopleAdd_clicked()
{
    QString qName = ui ->lineEditPeopleName->text();
    QString qGender = ui->dropDownPeopleGender->currentText();
    QString qBirth = ui->lineEditPeopleBirth->text();
    QString qDeath = ui->lineEditPeopleDeath->text();

    //smá jólagleði auka
    if(qName == "Secret Santa")
    {
        secretSanta secretsanta;
        secretsanta.exec();
        return;
    }

    if (qName.isEmpty()||qGender=="*Select"||qBirth.isEmpty())
    {
        ui->labelPeopleError->setText("<span style='color: #FF0000'>Everything with a * needs to be filled!</span");
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
    //If qBirth or qDeath is not a number, toUInt converts it to 0.
    //So this is an error when text is applied where number is expected.
    if(birth == 0)
    {
        QMessageBox::warning(this, "Warning","Error!\nYou have to enter a number for\nyear of birth.");
        ui->lineEditPeopleBirth->setText("");
        return;
    }

    if(death == 0) //If qBirth or qDeath is not a number, toUInt converts it to 0. So this is an error when text is applied where number is expected.
    {
        QMessageBox::warning(this, "Warning","Error!\nYou have to enter a number for\nyear of death.");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    if(QDate::currentDate().year() < birth)
    {
        QMessageBox::warning(this, "Warning","Error!\nPlease don't put birt in the future!");
        ui->lineEditPeopleBirth->setText("");
        return;
    }

    if(QDate::currentDate().year() < death)
    {
        QMessageBox::warning(this, "Warning","Error!\nPlease don't put death in the future!");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    if (death < birth && death!= constants::notDead) //Error if deathyear is before birthyear.
    {
        ui->labelPeopleError->setText("<span style='color: #FF0000'>Person can't die before they are born!</span>");
        ui->lineEditPeopleDeath->setText("");
        return;
    }

    bool onList = theLogic.insertPerson(name, gender, birth, death);
    if(onList)
    {
        ui->labelPeopleError->setText("<span style='color: #FF0000'>Person was already on the list.</span>");
        clearPeopleInsert();
        return;
    }
    else
    {
        ui->statusBar->showMessage("Person was successfully added", 3000);
        ui->lineEditPeopleFilter->setText("");
        ui->tablePeople->setSortingEnabled(false);
        displayAllPeople();
        ui->tablePeople->setSortingEnabled(true);
        //Clears all the fields that user filled out to add.
        clearPeopleInsert();
    }
}
//Next functions are to clear old error messages.
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
    ui->tableComputer->setSortingEnabled(false);
    ui->tableComputer->clearContents();
    ui->tableComputer->setRowCount(computers.size());
    for(unsigned int row = 0; row < computers.size(); row++)
    {
        computersWithPeople currComputer = computers[row];
        ui->tableComputer->setItem(row,0,new QTableWidgetItem(QString::number(currComputer.c.getId())));
        ui->tableComputer->setItem(row,1,new QTableWidgetItem(QString::fromStdString(currComputer.c.getName())));
        ui->tableComputer->setItem(row,2,new QTableWidgetItem(QString::fromStdString(currComputer.c.getType())));
        ui->tableComputer->setItem(row,3,new QTableWidgetItem(QString::number(currComputer.c.getYearCreated())));
        if(currComputer.c.getWasBuilt() > 0)
        {
            ui->tableComputer->setItem(row,4,new QTableWidgetItem("Yes"));
        }
        else
        {
            ui->tableComputer->setItem(row,4,new QTableWidgetItem("No"));
        }
        ui->tableComputer->showRow(row);
    }
    ui->tableComputer->setSortingEnabled(true);
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

peopleWithComputers MainWindow::getSelectedPerson()
{
    int id = getSelectedIdPeople();
    peopleWithComputers temp = theLogic.getPerson(id);
    return temp;
}

computersWithPeople MainWindow::getSelectedComputer()
{
    int id = getSelectedIdComputer();
    computersWithPeople temp = theLogic.getComputer(id);
    return temp;
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    //This is done so new changes will be displayed.
    //Even though done on the other tab.
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
    ui->ButtonPeopleEdit->setEnabled(true);
}

void MainWindow::on_buttonPeopleDelete_clicked()
{

    int answer = QMessageBox::question(this, "Confirm", "Are you sure you want to delete this person?");
    if(answer == QMessageBox::No)
    {
        ui->ButtonPeopleEdit->setEnabled(false);
        ui->buttonPeopleDelete->setEnabled(false);
        return;
    }

    int id = getSelectedIdPeople();

    theLogic.eraseChosenPeople(id);
    ui->tablePeople->setSortingEnabled(false);
    displayAllPeople();
    ui->tablePeople->setSortingEnabled(true);
    ui->ButtonPeopleEdit->setEnabled(false);
    ui->buttonPeopleDelete->setEnabled(false);
}

void MainWindow::on_buttonComputerAdd_clicked()
{
    QString qName = ui->lineEditComputerName->text();
    QString qType = ui->lineEditComputerType->text();
    QString qYearCreated = ui->lineEditComputerCreated->text();
    QString qWasBuilt = ui->dropDownComputerBuilt->currentText();

    if (qName.isEmpty()||qType.isEmpty()||qYearCreated.isEmpty()||qWasBuilt=="*Built?")
    {
        ui->labelComputerError->setText("<span style='color: #FF0000'>Everything with a * needs to be filled!</span>");
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

    if(QDate::currentDate().year() < yearCreated)
    {
        QMessageBox::warning(this, "Warning","Error!\nComputer cannot be created in the future!");
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
        ui->labelComputerError->setText("<span style='color: #FF0000'>Computer was already on the list.</span>");
        clearComputerInsert();
        return;
    }
    else
    {
        ui->statusBar->showMessage("Computer was successfully added", 3000);
        ui->lineEditComputersFilter->setText("");
        ui->tableComputer->setSortingEnabled(false);
        displayAllComputers();
        ui->tableComputer->setSortingEnabled(true);
        ui->ButtonComputersEdit->setEnabled(false);
        ui->buttonComputerDelete->setEnabled(false);
        clearComputerInsert();
    }
}

//Next functions are to clear old error message.
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
    ui->ButtonComputersEdit->setEnabled(true);
}

void MainWindow::on_buttonComputerDelete_clicked()
{
    int answer = QMessageBox::question(this, "Confirm", "Are you sure you want to delete this computer?");
    if(answer == QMessageBox::No)
    {
        ui->ButtonComputersEdit->setEnabled(false);
        ui->buttonComputerDelete->setEnabled(false);
        return;
    }

    int id = getSelectedIdComputer();
    theLogic.eraseChosenComputer(id);
    ui->tableComputer->setSortingEnabled(false);
    displayAllComputers();
    ui->tableComputer->setSortingEnabled(true);
    ui->buttonComputerDelete->setEnabled(false);
    ui->ButtonComputersEdit->setEnabled(false);
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

void MainWindow::on_ButtonPeopleEdit_clicked()
{
    editSelectedPerson();
}

void MainWindow::on_ButtonComputersEdit_clicked()
{
    editSelectedComputer();
}

void MainWindow::on_actionRightClicked_triggered()
{
    editSelectedPerson();
}

void MainWindow::on_actionComputerRightClicked_triggered()
{
    editSelectedComputer();
}

void MainWindow::editSelectedPerson()
{
    Edit edit;
    peopleWithComputers personToDisplay = getSelectedPerson();
    edit.setSelectedPerson(personToDisplay);
    edit.displayComputers(theLogic.allComputersSorted(1,1));
    bool edited = edit.exec();
    if(edited)
    {
        vector<int> checkedComputers = edit.getCheckedComputers();
        foreach (int comID, checkedComputers)
        {
            theLogic.insertConnection(personToDisplay.p.getId(), comID);
        }
        foreach (computers com, personToDisplay.creations)
        {
            int comID = com.getId();
            if ( std::find(checkedComputers.begin(), checkedComputers.end(), comID) == checkedComputers.end() )
            {
                theLogic.deleteConnection(personToDisplay.p.getId(),comID);
            }

        }

        bool success = theLogic.editPerson(edit.getPersonChanged());
        if(!success)
        {
            ui->statusBar->showMessage("This person was already in the database!", 2000);
            return;
        }
        ui->statusBar->showMessage("Changes were successfully submitted", 2000);
        ui->lineEditPeopleFilter->setText("");
        ui->tablePeople->setSortingEnabled(false);
        displayAllPeople();
        ui->tablePeople->setSortingEnabled(true);
        ui->ButtonPeopleEdit->setEnabled(false);
        ui->buttonPeopleDelete->setEnabled(false);
    }
}

void MainWindow::editSelectedComputer()
{
    editComputers editcomputers;
    computersWithPeople selectedComputer = getSelectedComputer();
    editcomputers.setSelectedComputer(selectedComputer);
    editcomputers.displayPeople(theLogic.allPeopleSorted(1,1));
    bool edited = editcomputers.exec();
    if(edited)
    {
        vector<int> checkedPeople = editcomputers.getCheckedPeople();
        foreach (int pepID, checkedPeople)
        {
            theLogic.insertConnection(pepID, selectedComputer.c.getId());
        }
        foreach (people pep, selectedComputer.creators)
        {
            int pepID = pep.getId();
            if ( std::find(checkedPeople.begin(), checkedPeople.end(), pepID) == checkedPeople.end() )
            {
                theLogic.deleteConnection(pepID, selectedComputer.c.getId());
            }

        }
        bool success = theLogic.editComputer(editcomputers.getComputerChanged());
        if(!success)
        {
            ui->statusBar->showMessage("This computer was already in the database!", 2000);
            return;
        }
        ui->statusBar->showMessage("Changes were successfully submitted", 2000);
        ui->lineEditComputersFilter->setText("");
        ui->tableComputer->setSortingEnabled(false);
        displayAllComputers();
        ui->tableComputer->setSortingEnabled(true);
        ui->ButtonComputersEdit->setEnabled(false);
        ui->buttonComputerDelete->setEnabled(false);
    }
}

void MainWindow::on_actionOpen_readme_file_triggered()
{
    readMe readme;
    bool success = readme.connectoToFile();
    if (success)
        readme.exec();
    else
        return;
}

void MainWindow::on_tableComputer_entered(const QModelIndex &index)
{
    ui->tableComputer->setToolTip("To display more information double click.");
}

void MainWindow::on_tablePeople_entered(const QModelIndex &index)
{
    ui->tablePeople->setToolTip("To display more information double click.");
}

void MainWindow::on_tableComputer_doubleClicked(const QModelIndex &index)
{
    ClickComputer cc;
    computersWithPeople selectedComputer = getSelectedComputer();
    cc.setSelectedComputer(selectedComputer);
    cc.exec();
}

void MainWindow::on_tablePeople_doubleClicked(const QModelIndex &index)
{
    peopleWithComputers selectedPerson = getSelectedPerson();
    ClickScientist cs;
    cs.setSelectedPerson(selectedPerson);
    cs.exec();
}

void MainWindow::on_tablePeople_customContextMenuRequested(const QPoint & pos)
{
//    Adds the action actionRightClicked to the menu that pops up when
//            right clicked.
    QMenu *menu=new QMenu(this);
    menu->addAction(ui->actionRightClicked);
    menu->exec(ui->tablePeople->viewport()->mapToGlobal(pos));
}

void MainWindow::on_tableComputer_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu=new QMenu(this);
    menu->addAction(ui->actionComputerRightClicked);
    menu->exec(ui->tableComputer->viewport()->mapToGlobal(pos));
}
