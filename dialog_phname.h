#ifndef DIALOG_PHNAME_H
#define DIALOG_PHNAME_H

#include <QDialog>
//window used to get a pharmacy name

namespace Ui {
class Dialog_PhName;
}

class Dialog_PhName : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_PhName(QWidget *parent = 0);
    ~Dialog_PhName();
    QString getName();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_PhName *ui;
    QString name;
};

#endif // DIALOG_PHNAME_H
