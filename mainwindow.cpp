#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Pharmacie.h"
#include <QTextStream>
#include "Pharmaciemanager.h"
#include <QErrorMessage>
#include "dialog_phname.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QThread>
#include <QPainter>
#include <QShortcut>
#include <QCompleter>
#include "result.h"
#include "modifier.h"


using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentPharmacie(NULL),
    pharmacieChanged(false)

{
    ui->setupUi(this);
    connect(ui->actionNouvelle_Pharmacie,SIGNAL(triggered()),this,SLOT(addPharmacie()));
    connect(ui->actionModifierPharmacie,SIGNAL(triggered()),this,SLOT(modify()));
    connect(ui->actionSauvegarder,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(uncheck2()));
    connect(ui->checkBox_2,SIGNAL(clicked()),this,SLOT(uncheck1()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O), this, SLOT(addPharmacie()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_M),this,SLOT(modify()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S),this,SLOT(save()));
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();


}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::addPharmacie()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("charger les données"),"/path/to/file/",tr("txt Files (*.txt)"));
    if (!fileName.isEmpty())
    {
    dial=new Dialog_PhName(this);
    dial->exec();
    QString name=dial->getName();
    if (dial->getName().isEmpty()) {name="sans_titre";}
    Pharmacie *database=new Pharmacie(name);
    PM.parser(database,fileName, name,false);
    ui->comboBox->insertItem(-1,name);
    setCurrentPharmacie(name);
    ui->comboBox->setCurrentIndex(0);
    updateDisplay();
    StringListsAdder(name);
    histogram();
    updateCompleter(name);
    delete dial;
    }




}
void MainWindow::modify()
{
    if (currentPharmacie!=NULL) {
    pharmacieChanged=true;
    mod=new Modifier(currentPharmacie,ui->comboBox->currentText());
    mod->show();
    }
    else {
        ui->statusBar->showMessage("veuillez d'abord charger une pharmacie",1000);
    }

}

void MainWindow::save()
{
    if (currentPharmacie!=NULL) {
    QString fileName = QFileDialog::getSaveFileName(this, tr("sauvegarder la pharmacie"),"/path/to/file/",tr("txt Files (*.txt)"));
        if (!fileName.isEmpty()) {
            currentPharmacie->save(fileName);
            ui->statusBar->showMessage("la pharmacie courante a été sauvegardée");
        }

    }
    else {
        ui->statusBar->showMessage("veuillez d'abord charger une pharmacie",1000);
    }
}

bool MainWindow::pharmacieLoaded()
{
    return (currentPharmacie!=NULL);
}

void MainWindow::StringListsAdder(QString pharmacieName)
{
    QStringList listNameM;
    QStringList listNameS;
    for (int i =0; i<currentPharmacie->getMedicin().size();i++) {
        listNameM.append(QString::fromStdString(currentPharmacie->getMedicin().at(i)->getName()));
    }
    for (int i =0; i<currentPharmacie->getSideEffect().size();i++) {
        listNameS.append(QString::fromStdString(currentPharmacie->getSideEffect().at(i)->getName()));
    }
    QCompleter *cm=new QCompleter(listNameM);
    QCompleter *cs=new QCompleter(listNameS);
    cm->setCaseSensitivity(Qt::CaseInsensitive);
    cs->setCaseSensitivity(Qt::CaseInsensitive);
    cm->setCompletionMode(QCompleter::InlineCompletion);
    cs->setCompletionMode(QCompleter::InlineCompletion);
    this->hashCompleterM[pharmacieName]=cm;
    this->hashCompleterS[pharmacieName]=cs;
}
void MainWindow::updateDisplay()
{
    ui->textEdit->clear();
    currentPharmacie->displayMedicin(ui->textEdit);

}

void MainWindow::setCurrentPharmacie(const QString &name)
{
    currentPharmacie=PM.getmPhar()[name];
}

void MainWindow::test(const Pharmacie &cphar)
{
    //cout<<cphar.getName()<<endl;
}

void MainWindow::histogram()
{
    ui->tableWidget->setRowCount(currentPharmacie->getSideEffect().size());
    ui->tableWidget->setColumnCount(2);

    for (int i=0;i<currentPharmacie->getSideEffect().size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(
                                     QString::fromStdString(currentPharmacie->getSideEffect().at(i)->getName())));
        QWidget *bar=new QWidget();
        bar->setFixedHeight(25);
        bar->setFixedWidth(10*(currentPharmacie->getSideEffect().at(i)->numberOfMedicin()));
        bar->setStyleSheet(QString("background-color: #c0c0c0;"));
        ui->tableWidget->setCellWidget(i,1,bar);


    }
}
void MainWindow::quickResearchM()
{
    if (ui->lineEdit->text().isEmpty())
    {
        ui->statusBar->showMessage("veuillez remplir l'un des 2 champs");
        return;
    }
    else if (!currentPharmacie->medicinExist(currentPharmacie->normalize(ui->lineEdit->text().toStdString(),true))) {
        ui->statusBar->showMessage("ce médicament n'éxiste pas, vous pouvez l'ajouter avec ctrl+m",1000);
        return;
    }
    else {
        Result *res=new Result(this);
        res->QRMedicin(currentPharmacie,ui->lineEdit->text());
        res->show();
    }
}

void MainWindow::quickResearchS()
{
    if (ui->lineEdit_2->text().isEmpty())
    {
        ui->statusBar->showMessage("veuillez remplir l'un des 2 champs");
        return;
    }
    else if (!currentPharmacie->sideExist(currentPharmacie->normalize(ui->lineEdit_2->text().toStdString(),false))) {
        ui->statusBar->showMessage("cet effet secondaire n'éxiste pas, vous pouvez l'ajouter avec ctrl+m",1000);
        return;
    }
    else {
        Result *res=new Result(this);
        res->QRSide(currentPharmacie,ui->lineEdit_2->text());
        res->show();
    }
}
void MainWindow::advancedResearch()
{
    if (ui->lineEdit_3->text().isEmpty())
    {
        ui->statusBar->showMessage("veuillez remplir le champs");
        return;
    }
    else if (!currentPharmacie->medicinExist(currentPharmacie->normalize(ui->lineEdit_3->text().toStdString(),true))) {
        ui->statusBar->showMessage("ce médicament n'éxiste pas, vous pouvez l'ajouter avec ctrl+m",1000);
        return;
    }
    Result *res=new Result(this);
    if (ui->checkBox->isChecked())
    {
        res->AR2(currentPharmacie,ui->lineEdit_3->text());
    }
    else if (ui->checkBox_2->isChecked())
    {
        res->ARrandom(currentPharmacie,ui->lineEdit_3->text());
    }
    else if (ui->spinBox->value()==0)
    {
        res->AR(currentPharmacie,ui->lineEdit_3->text());
    }
    else {
        res->AR(currentPharmacie,ui->lineEdit_3->text(),ui->spinBox->value());
    }
    res->show();
}

void MainWindow::updateCompleter(QString pharmacieName)
{
    ui->lineEdit->setCompleter(hashCompleterM[pharmacieName]);
    ui->lineEdit_3->setCompleter(hashCompleterM[pharmacieName]);
    ui->lineEdit_2->setCompleter(hashCompleterS[pharmacieName]);

}
void MainWindow::uncheck1()
{
    if (ui->checkBox->isChecked())
    {
        ui->checkBox->setChecked(false);
    }
}
void MainWindow::uncheck2()
{
    if (ui->checkBox_2->isChecked())
    {
        ui->checkBox_2->setChecked(false);
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    setCurrentPharmacie(arg1);
    histogram();
    this->updateDisplay();
    if (pharmacieChanged)
    {
        StringListsAdder(arg1);
        pharmacieChanged=false;
    }
    updateCompleter(arg1);

}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_pushButton_clicked()
{
    quickResearchM();
}

void MainWindow::on_pushButton_2_clicked()
{
    quickResearchS();
}


void MainWindow::on_pushButton_3_clicked()
{
    advancedResearch();
}

void MainWindow::on_pushButton_4_clicked()
{
    Result *res=new Result(this);
    res->displayHelp();
    res->show();
}
