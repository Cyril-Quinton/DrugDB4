#ifndef RESULT_H
#define RESULT_H
#include <Pharmacie.h>

#include <QDialog>


namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT
    
public:
    explicit Result(QWidget *parent = 0);
    ~Result();
    void QRMedicin(Pharmacie *current,QString name);
    void QRSide(Pharmacie *current, QString name);
    void AR2(Pharmacie *current, QString name);
    void ARrandom(Pharmacie *current, QString name);
    void AR(Pharmacie * current, QString name);
    void AR(Pharmacie *current, QString name, int scoreMin);
    void displayHelp();
private slots :

private:
    Ui::Result *ui;
};

#endif // RESULT_H
