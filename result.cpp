#include "result.h"
#include "ui_result.h"
#include "Pharmacie.h"
#include "Medicin.h"
#include <iostream>
#include <fstream>
#include <sstream>

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
}
void Result::QRMedicin(Pharmacie *current,QString name)
{
    string _name=name.toStdString();
    QString message="Effets secondaires associés au ";
    message.append(name);
    message.append(" :\n");
    ui->textEdit->append(message);
    current->displaySideEffect(current->normalize(_name,true),ui->textEdit);
}
void Result::QRSide(Pharmacie *current, QString name)
{
    QString message="Médicaments associés à l'effet secondaire : ";
    message.append(name);
    message.append("\n");
    ui->textEdit->append(message);
    string _name=name.toStdString();
    current->displayMedicin(current->normalize(_name,false),ui->textEdit);
}
void Result::AR(Pharmacie *current, QString name)
{
    QString message="liste de médicaments partageant un maximum d'effets secondaires avec le ";
    message.append(name);
    message.append("\n");
    message.append("nombre d'effets secondaires en commun : ");
    ui->textEdit->append(message);
    string _name=name.toStdString();
    current->displayMostSideShared(current->normalize(_name,true),ui->textEdit);
}
void Result::AR(Pharmacie *current, QString name, int scoreMin)
{
    QString message="liste de médicaments partageant au moins ";
    message.append(QString::number(scoreMin));
    message.append(" effets secondaires avec le ");
    message.append(name);
    message.append("\n");
    ui->textEdit->append(message);
    string _name=name.toStdString();
    current->displayMostSideShared(current->normalize(_name,true),ui->textEdit,scoreMin);
}
void Result::AR2(Pharmacie *current, QString name)
{
    QString message="2 premiers médicaments partageant au moins 1 effet secondaire avec le ";
    message.append(name);
    message.append("\n");
    ui->textEdit->append(message);
    string _name=name.toStdString();
    current->displayMostSideSharedQuick(current->normalize(_name,true),ui->textEdit);
}
void Result::ARrandom(Pharmacie *current, QString name)
{
    QString message="Médicament au hasard partageant au moins un effet secondaire avec le ";
    message.append(name);
    message.append("\n");
    ui->textEdit->append(message);
    string _name=name.toStdString();
    current->displayMedicinRandom(current->normalize(_name,true),ui->textEdit);
}
void Result::displayHelp()
{
    ifstream file;
    file.open("doc/help.txt",ios::in);

    if (file)
    {
        string line;
        while(getline(file,line)){
            ui->textEdit->append(QString::fromStdString(line));
        }
     }
    file.close();
}

Result::~Result()
{
    delete ui;
}
