#include "dialog_phname.h"
#include "ui_dialog_phname.h"

Dialog_PhName::Dialog_PhName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_PhName)
{
    ui->setupUi(this);
}

Dialog_PhName::~Dialog_PhName()
{
    delete ui;
}
QString Dialog_PhName::getName()
{
    return name;
}

void Dialog_PhName::on_buttonBox_accepted()
{
    name=ui->lineEdit->text();
    close();
}
