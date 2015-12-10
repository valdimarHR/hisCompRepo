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
    ui->listPeople->clear();
    for(unsigned int i = 0; i < people.size(); i++)
    {
        peopleWithComputers currPerson = people[i];
        ui->listPeople->addItem(QString::fromStdString(currPerson.p.getName()));
    }
}

void MainWindow::on_pushButton_clicked()
{
    displayAllPeople();
}
