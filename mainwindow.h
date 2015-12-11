#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Models/peoplewithcomputers.h"
#include "Processor/logic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_tabWidget_tabBarClicked(int index);

    void on_buttonPeopleAdd_clicked();

private:
    void displayAllPeople();
    void displayAllComputers();
    void displayPeople(vector<peopleWithComputers>);
    void displayComputers(vector<computersWithPeople>);
    Ui::MainWindow *ui;
    logic theLogic;
};

#endif // MAINWINDOW_H
