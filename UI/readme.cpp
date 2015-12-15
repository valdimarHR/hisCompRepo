#include "readme.h"
#include "ui_readme.h"

readMe::readMe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::readMe)
{
    ui->setupUi(this);
    QFile file(":/files/README.txt");
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}

readMe::~readMe()
{
    delete ui;
}

void readMe::on_ButtonClose_clicked()
{
    this->close();
}
