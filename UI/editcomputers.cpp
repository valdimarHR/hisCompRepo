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
        ui->labelComputerEditError->setText("<span style='color: #FF0000'>Everything needs to be filled before submition.</span>");
        return;
    }

    if(yearCreated == 0) //því ef toUnt convertar texta í 0;
    {
        QMessageBox::warning(this, "Warning", "Don't put a text for year created!");
        ui->lineEditComputerYearCreated->setText("");
        return;
    }

    if(QDate::currentDate().year() < yearCreated)
    {
        QMessageBox::warning(this, "Warning","Error!\nComputer cannot be made in the future!");
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

//    ui->listComputersCreators->clear();
//    for(unsigned int i=0; i<selectedComputer.creators.size(); i++)
//    {
//        string peopledisplay;
//        peopledisplay = selectedComputer.creators[i].getName() + " " + to_string(selectedComputer.creators[i].getBirth()) + " - ";
//        peopledisplay += to_string(selectedComputer.creators[i].getDeath());
//        ui->listComputersCreators->addItem(QString::fromStdString(peopledisplay));
//    }
}

void editComputers::displayPeople(vector<peopleWithComputers> people)
{
    ui->tableComputerCreators->setSortingEnabled(false);
    ui->tableComputerCreators->hideColumn(0);
    ui->tableComputerCreators->setColumnWidth(2,330);
    ui->tableComputerCreators->setColumnWidth(1,70);
    ui->tableComputerCreators->clearContents();
    ui->tableComputerCreators->setRowCount(people.size());
    for(unsigned int row = 0; row < people.size(); row++)
    {
        peopleWithComputers currPerson = people[row];
        QTableWidgetItem *checkbox = new QTableWidgetItem();
        for(int i = 0; i < selectedComputer.creators.size(); i++)
        {

            if(currPerson.p.getId() == selectedComputer.creators[i].getId())
            {
                checkbox->setCheckState(Qt::Checked);
                break;
            }
            else
            {
                checkbox->setCheckState(Qt::Unchecked);
            }
        }
        ui->tableComputerCreators->setItem(row,0,new QTableWidgetItem(QString::number(currPerson.p.getId())));
        ui->tableComputerCreators->setItem(row,1,checkbox);
        ui->tableComputerCreators->setItem(row,2,new QTableWidgetItem(QString::fromStdString(currPerson.p.getName())));
        ui->tableComputerCreators->setItem(row,3,new QTableWidgetItem(QString::number(currPerson.p.getBirth())));
    }
    ui->tableComputerCreators->setSortingEnabled(true);
}

vector<int> editComputers::getCheckedPeople()
{
    vector<int> checkedPeopleId;
    int rows = ui->tableComputerCreators->rowCount();
    for(int i = 0; i < rows; i++)
    {
        if(ui->tableComputerCreators->item(i,1)->data(Qt::CheckStateRole) == Qt::Checked)
        {
            checkedPeopleId.push_back(ui->tableComputerCreators->item(i,0)->text().toInt());
        }
    }
    return checkedPeopleId;
}

void editComputers::on_ButtonCancel_clicked()
{
    this->done(0);
}
