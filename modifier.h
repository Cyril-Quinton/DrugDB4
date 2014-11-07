#ifndef MODIFIER_H
#define MODIFIER_H

#include <QMainWindow>
#include "Pharmacie.h"
#include <QCompleter>

namespace Ui {
class Modifier;
}

class Modifier : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Modifier(Pharmacie *current,QString currentName,QWidget *parent = 0);
    //add completer from pharmacy which is modified
    void stringListAdder();
    ~Modifier();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();





private:
    Ui::Modifier *ui;
    Pharmacie *current;

    QCompleter *cm;
    QCompleter *cs;

};

#endif // MODIFIER_H
