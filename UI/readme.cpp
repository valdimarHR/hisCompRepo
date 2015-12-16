#include "readme.h"
#include "ui_readme.h"

readMe::readMe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::readMe)
{
    ui->setupUi(this);
}

bool readMe::connectoToFile()
{
    QFile file("README.txt");
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        qFatal( "Could not open the file" );
        return false;
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
    return true;
}

readMe::~readMe()
{
    delete ui;
}

void readMe::on_ButtonClose_clicked()
{
    this->close();
}
