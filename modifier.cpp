#include "modifier.h"
#include "ui_modifier.h"
#include "Pharmacie.h"
#include "iostream"
#include <fstream>
#include <sstream>
#include "mainwindow.h"
#include <QStringList>

Modifier::Modifier(Pharmacie *_current,QString _currentName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Modifier)
{
    ui->setupUi(this);
    current=_current;
    stringListAdder();
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(close()));


}

Modifier::~Modifier()
{
    delete ui;
}
void Modifier::stringListAdder()
{
    QStringList listNameM;
    QStringList listNameS;
    for (int i =0; i<current->getMedicin().size();i++) {
        listNameM.append(QString::fromStdString(current->getMedicin().at(i)->getName()));
    }
    for (int i =0; i<current->getSideEffect().size();i++) {
        listNameS.append(QString::fromStdString(current->getSideEffect().at(i)->getName()));
    }
    cm=new QCompleter(listNameM,this);
    cs=new QCompleter(listNameS,this);
    cm->setCaseSensitivity(Qt::CaseInsensitive);
    cs->setCaseSensitivity(Qt::CaseInsensitive);
    cm->setCompletionMode(QCompleter::InlineCompletion);
    cs->setCompletionMode(QCompleter::InlineCompletion);
    ui->lineEdit_3->setCompleter(cm);
    ui->lineEdit_4->setCompleter(cm);
    ui->lineEdit_6->setCompleter(cs);
}

void Modifier::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty())
    {
        ui->statusbar->showMessage("veuillez rentrer un nom de médicament",1000);
    }

    else if (current->medicinExist(current->normalize(ui->lineEdit->text().toStdString(),true)))
    {
        ui->statusbar->showMessage("Ce médicament existe déja dans cette pharmacie, aucun ajout n'a été effectué",1000);
    }
    else {
        string name=current->normalize(ui->lineEdit->text().toStdString(),true);
        string sideEffect=ui->textEdit->toPlainText().toStdString();
        istringstream se(sideEffect);
        string line;
        vector <string> vectorSide;
        while(std::getline(se,line))
        {
            string lineN=current->normalize(line,false);
            vectorSide.push_back(lineN);
        }

        current->medicinAdder(name,vectorSide);

    if (vectorSide.size()==0)
    {
        ui->statusbar->showMessage("Nouveau médicament ajouté mais sans effet secondaire",1000);
        stringListAdder();
    }
    else
    {
        ui->statusbar->showMessage("Nouveau médicament ajouté avec succès",1000);
        stringListAdder();
    }
    }
}

void Modifier::on_pushButton_2_clicked()
{
    if (ui->lineEdit_3->text().isEmpty())
    {
        ui->statusbar->showMessage("veuillez taper le nom du médicament à supprimer",1000);
    }
    else if (!current->medicinExist(current->normalize(ui->lineEdit_3->text().toStdString(),true)))
    {
        ui->statusbar->showMessage("ce médicament n'éxiste pas",1000);
    }
    else
    {
        current->suppressMedicin(current->normalize(ui->lineEdit_3->text().toStdString(),true));
        ui->statusbar->showMessage("médicament supprimé",1000);
        stringListAdder();
    }
}

void Modifier::on_pushButton_3_clicked()
{
    string name=current->normalize(ui->lineEdit_4->text().toStdString(),true);
    string Nname=current->normalize(ui->lineEdit_5->text().toStdString(),true);
    if (ui->lineEdit_4->text().isEmpty() || ui->lineEdit_5->text().isEmpty())
    {
        ui->statusbar->showMessage("veuillez remplir les 2 champs",1000);
    }
    else if (!current->medicinExist(name))
    {
        ui->statusbar->showMessage("ce médicament n'existe pas",1000);

    }
    else
    {
        current->modifyNameMedicin(name,Nname);
        ui->statusbar->showMessage("nom du médicament modifié avec succès",1000);
        stringListAdder();
    }

}

void Modifier::on_pushButton_4_clicked()
{
    string name=current->normalize(ui->lineEdit_6->text().toStdString(),false);
    string Nname=current->normalize(ui->lineEdit_7->text().toStdString(),false);
    if (ui->lineEdit_6->text().isEmpty() || ui->lineEdit_7->text().isEmpty())
    {
        ui->statusbar->showMessage("veuillez remplir les 2 champs",1000);
    }
    else if (!current->sideExist(name))
    {
        ui->statusbar->showMessage("cet effet secondaire n'existe pas",1000);

    }
    else
    {
        current->modifyNameSide(name,Nname);
        ui->statusbar->showMessage("nom de l'effet secondaire modifié avec succès",1000);
        stringListAdder();
    }

}


