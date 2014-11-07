#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Pharmaciemanager.h"
#include "dialog_phname.h"
#include <QHBoxLayout>
#include "Pharmacie.h"
#include <QCompleter>
#include "modifier.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots :
    void addPharmacie();
    void test(const Pharmacie &cphar);
    void histogram();
private slots:
    void setCurrentPharmacie(const QString &name);
    //update drug's list display
    void updateDisplay();
    //add completers from a new current phrmacy or a modified pharmacy
    void StringListsAdder(QString pharmacieName);
    void updateCompleter(QString pharmacieName);
    //display side effects associated with a medicin
    void quickResearchM();
    //display Medicin associated with a side effect
    void quickResearchS();
    void advancedResearch();
    //return true if at least one pharmacy is loaded
    bool pharmacieLoaded();
    //show a  modifier window to perform modification on the
    //current pharmacy
    void modify();
    //save the current pharmacy
    void save();
    //uncheck ui->checkbox
    void uncheck1();
    //uncheck ui->checkbx_2
    void uncheck2();

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:

    Ui::MainWindow *ui;
    PharmacieManager PM;
    Dialog_PhName *dial;
    Modifier *mod;
    Pharmacie *currentPharmacie;
    std::map<QString, QCompleter*> hashCompleterS;
    std::map<QString, QCompleter*> hashCompleterM;
    bool pharmacieChanged;
};

#endif // MAINWINDOW_H
